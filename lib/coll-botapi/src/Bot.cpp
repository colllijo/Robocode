#include "Bot.hpp"
#include "ConnectionEvents.hpp"
#include <iostream>

Bot::Bot(const BotInfo &botInfo, const std::string &serverURL,
		 const std::string &serverSecret)
	: internals(std::make_unique<BotInternals>(this, botInfo, serverURL,
											   serverSecret)) {}

Bot::~Bot() = default;

void Bot::start() { internals->start(); }

void Bot::onConnected(const Events::Connection::ConnectedEvent &event) {
	std::cout << "connected\n";
}
void Bot::onDisconnected(const Events::Connection::DisconnectedEvent &event) {}
void Bot::onConnectionError(
	const Events::Connection::ConnectionErrorEvent &event) {}
