#include "internals/BotInternals.hpp"

#include <iostream>

BotInternals::BotInternals(const BotInfo &botInfo, const std::string &serverUrl,
						   const std::string &serverSecret)
	: botInfo(std::make_unique<BotInfo>(botInfo)) {
	this->serverURL = serverUrl.empty() ? getServerURLFromEnv() : serverUrl;
	this->serverSecret =
		serverSecret.empty() ? getServerSecretFromEnv() : serverSecret;

	initWebSocket();
}
BotInternals::~BotInternals() = default;

void BotInternals::initWebSocket() {
	webSocket.disablePerMessageDeflate();
	webSocket.setOnMessageCallback(
		[this](const ix::WebSocketMessagePtr &msg) { this->onMessage(msg); });
}

void BotInternals::onMessage(const ix::WebSocketMessagePtr &msg) {
	switch (msg->type) {
	case ix::WebSocketMessageType::Open:
	case ix::WebSocketMessageType::Error:
	case ix::WebSocketMessageType::Close:
	case ix::WebSocketMessageType::Ping:
	case ix::WebSocketMessageType::Pong:
	case ix::WebSocketMessageType::Fragment:
		break;
	case ix::WebSocketMessageType::Message:
		handleMessage(nlohmann::json::parse(msg->str));
		break;
	}
}

void BotInternals::handleMessage(const nlohmann::json &message) {
	std::cout << "Received:\n" << message.dump(4) << "\n";

	switch (Message::typeFromString(message.value("type", "None"))) {
	case Message::Type::ServerHandshake:
		handleServerHandshake(message);
		break;
	}
}

void BotInternals::handleServerHandshake(const nlohmann::json &message) {
	nlohmann::json botHandshake = Message::createBotHandshake(
		message.value("sessionId", ""), serverSecret, botInfo);
	std::cout << "Sending:\n" << botHandshake.dump(4) << "\n";

	webSocket.send(botHandshake.dump());
}

void BotInternals::start() {
	std::cout << "Starting Bot..." << '\n';
	setRunning(true);
	connect();
}

void BotInternals::connect() {
	webSocket.setUrl(serverURL);
	webSocket.disablePerMessageDeflate();
	webSocket.start();
}
