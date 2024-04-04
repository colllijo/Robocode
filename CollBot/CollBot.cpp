#include "CollBot.hpp"
#include "coll-tankroyal-botapi/BotInfo.hpp"

#include <iostream>

CollBot::CollBot(const BotInfo &botInfo) : Bot(botInfo){};
CollBot::~CollBot() = default;

int main() {
	auto bot =
		std::make_unique<CollBot>(BotInfo::fromFile("../CollBot/CollBot.json"));
	bot->start();

	int num;
	std::cin >> num;

	return num;
}
