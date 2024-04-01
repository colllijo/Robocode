#ifndef COLLBOT_HPP
#define COLLBOT_HPP

#include <iostream>
#include <memory>

#include "coll-tankroyal-botapi/Bot.hpp"
#include "coll-tankroyal-botapi/BotInfo.hpp"

class CollBot : public Bot {
  public:
	CollBot(const BotInfo &botInfo);
	~CollBot();
};

#endif
