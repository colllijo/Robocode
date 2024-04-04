#ifndef COLL_TANKROYAL_BOTAPI_BOT_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_HPP

#include <memory>
#include <string>

#include "BotInfo.hpp"
#include "coll-tankroyal-botapi/events/ConnectionEvents.hpp"
#include "coll-tankroyal-botapi/internals/BotEventHandler.hpp"
#include "internals/BotInternals.hpp"

#pragma once

class BotInternals;
class Bot {
  public:
	Bot(const BotInfo &BotInfo, const std::string &serverURL = std::string(),
		const std::string &serverSecret = std::string());
	~Bot();

	void start();

	void onConnected(const Events::Connection::ConnectedEvent &event);
	void onDisconnected(const Events::Connection::DisconnectedEvent &event);
	void
	onConnectionError(const Events::Connection::ConnectionErrorEvent &event);

  private:
	std::unique_ptr<BotInternals> internals;
};

#endif
