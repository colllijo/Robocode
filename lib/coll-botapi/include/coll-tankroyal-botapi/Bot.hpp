#ifndef COLL_TANKROYAL_BOTAPI_BOT_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_HPP

#include <exception>
#include <memory>
#include <string>

#include <fmt/format.h>

#include "BotInfo.hpp"
#include "events/ConnectionEvents.hpp"
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

  protected:
	std::unique_ptr<BotInternals> internals;
};

#endif
