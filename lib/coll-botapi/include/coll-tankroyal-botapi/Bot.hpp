#ifndef COLL_TANKROYAL_BOTAPI_BOT_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_HPP

#include <memory>
#include <string>

#include "BotInfo.hpp"
#include "internals/BotInternals.hpp"

#pragma once

class Bot {
  public:
	Bot(const BotInfo &BotInfo, const std::string &serverURL = std::string(),
		const std::string &serverSecret = std::string());
	~Bot();

	void start();

  private:
	std::unique_ptr<BotInternals> internals;
};

#endif
