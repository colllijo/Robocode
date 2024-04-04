#include "internals/BotInternals.hpp"
#include "ConnectionEvents.hpp"

#include <iostream>

BotInternals::BotInternals(Bot *bot, const BotInfo &botInfo,
						   const std::string &serverUrl,
						   const std::string &serverSecret)
	: botInfo(std::make_unique<BotInfo>(botInfo)),
	  botEventHandler(std::make_unique<BotEventHandler>(bot)) {
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
		botEventHandler->onConnected->publish(
			Events::Connection::ConnectedEvent(serverURL));
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

void BotInternals::handleServerHandshake(const nlohmann::json &message) {
	nlohmann::json botHandshake = Events::Message::createBotHandshake(
		message.value("sessionId", ""), serverSecret, botInfo);

	webSocket.send(botHandshake.dump());
}

void BotInternals::handleGameStarted(const nlohmann::json &message) {
	int id = message.value("myId", 0);
	nlohmann::json botReady = Events::Message::createBotReady();

	webSocket.send(botReady.dump());
}

/* { */
/* 	"arenaHeight" : 600, "arenaWidth" : 800, "defaultTurnsPerSecond" : 30, */
/* 		"gameType" : "classic", */
/* 					 "gunCoolingRate" : 0.1, */
/* 					 "isArenaHeightLocked" : true, */
/* 											 "isArenaWidthLocked" */
/* 		: true, */
/* 		  "isGunCoolingRateLocked" : true, */
/* 									 "isMaxInactivityTurnsLocked" */
/* 		: true, */
/* 		  "isMaxNumberOfParticipantsLocked" : true, */
/* 											  "isMinNumberOfParticipantsLocked"
 */
/* 		: true, */
/* 		  "isNumberOfRoundsLocked" : true, */
/* 									 "isReadyTimeoutLocked" */
/* 		: false, */
/* 		  "isTurnTimeoutLocked" : false, */
/* 								  "maxInactivityTurns" : 450, */
/* 								  "minNumberOfParticipants" : 2, */
/* 								  "numberOfRounds" : 10, */
/* 								  "readyTimeout" : 1000000, */
/* 								  "turnTimeout" : 30000 */
/* } */

void BotInternals::handleRoundStarted(const nlohmann::json &message) {}

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
