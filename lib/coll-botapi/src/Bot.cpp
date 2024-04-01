#include "Bot.hpp"
#include "BotInfo.hpp"

Bot::Bot(const BotInfo &botInfo, const std::string &serverURL,
		 const std::string &serverSecret)
	: internals(
		  std::make_unique<BotInternals>(botInfo, serverURL, serverSecret)) {}

Bot::~Bot() = default;

void Bot::start() { internals->start(); }
