#include "internals/BotInternals.hpp"

/* --- Initialization --- */
BotInternals::BotInternals(Bot* bot, const BotInfo& botInfo,
    const std::string& serverUrl,
    const std::string& serverSecret)
    : botInfo(std::make_unique<BotInfo>(botInfo))
    , botEventHandler(std::make_unique<BotEventHandler>(bot))
    , closedLatch(1)
{
    this->serverURL = serverUrl.empty() ? getServerURLFromEnv() : serverUrl;
    this->serverSecret = serverSecret.empty() ? getServerSecretFromEnv() : serverSecret;

    initWebSocket();
}
BotInternals::~BotInternals()
{
    if (webSocket.getReadyState() == ix::ReadyState::Open) {
        webSocket.stop();
    }
}

void BotInternals::initWebSocket()
{
    webSocket.disablePerMessageDeflate();
    webSocket.setOnMessageCallback(
        [this](const ix::WebSocketMessagePtr& msg) { this->onMessage(msg); });
}

/* --- Logging --- */
void BotInternals::print(const std::string& msg)
{
    std::fprintf(stdout, "%s", msg.c_str());
}

void BotInternals::printErr(const std::string& err)
{
    std::fprintf(stderr, "%s", err.c_str());
}

/* --- Websockets --- */
void BotInternals::onMessage(const ix::WebSocketMessagePtr& msg)
{
    switch (msg->type) {
    case ix::WebSocketMessageType::Open:
        botEventHandler->onConnected->publish(
            Events::Connection::ConnectedEvent(serverURL));
        break;
    case ix::WebSocketMessageType::Close:
        botEventHandler->onDisconnected->publish(
            Events::Connection::DisconnectedEvent(
                serverURL, msg->closeInfo.remote, msg->closeInfo.code,
                msg->closeInfo.reason));
        closedLatch.count_down();
        break;
    case ix::WebSocketMessageType::Error:
        botEventHandler->onConnectionError->publish(
            Events::Connection::ConnectionErrorEvent(serverURL,
                msg->errorInfo.reason));
        closedLatch.count_down();
    case ix::WebSocketMessageType::Message:
        handleMessage(nlohmann::json::parse(msg->str));
        break;
    default:
        break;
    }
}

void BotInternals::handleMessage(const nlohmann::json& message)
{
    switch (Events::typeFromString(message.value("type", "None"))) {
    case Events::Type::ServerHandshake:
        handleServerHandshake(message);
        break;
    case Events::Type::GameStartedEventForBot:
        handleGameStarted(message);
        break;
    case Events::Type::RoundStartedEvent:
        handleRoundStarted(message);
        break;
    }
}

void BotInternals::handleServerHandshake(const nlohmann::json& message)
{
    nlohmann::json botHandshake = Events::Message::createBotHandshake(
        message.value("sessionId", ""), serverSecret, botInfo);

    webSocket.send(botHandshake.dump());
}

void BotInternals::handleGameStarted(const nlohmann::json& message)
{
    int id = message.value("myId", 0);
    nlohmann::json botReady = Events::Message::createBotReady();

    webSocket.send(botReady.dump());
}

void BotInternals::handleGameEnded(const nlohmann::json& message)
{
    botEventHandler->onGameEnded->publish(Events::Game::GameEndedEvent(
        message["numberOfRounds"],
        Events::Game::messageToBotResult(message["result"])));
}

void BotInternals::handleGameAborted(const nlohmann::json& message)
{
    botEventHandler->onGameAborted->publish(Events::Game::GameAbortedEvent());
}

void BotInternals::handleRoundStarted(const nlohmann::json& message) { }

void BotInternals::start()
{
    print("Starting Bot...\n");
    setRunning(true);
    connect();
    closedLatch.wait();
    print("Bot stopped.\n");
    webSocket.stop();
}

void BotInternals::connect()
{
    webSocket.setUrl(serverURL);
    webSocket.disablePerMessageDeflate();
    webSocket.start();
}
