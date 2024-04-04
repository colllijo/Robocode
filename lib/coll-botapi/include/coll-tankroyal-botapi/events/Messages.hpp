#ifndef COLL_TANKROYAL_BOTAPI_MESSAGES_HPP
#define COLL_TANKROYAL_BOTAPI_MESSAGES_HPP

#include <string>

#include <nlohmann/json.hpp>

#include "../BotInfo.hpp"
#include "nlohmann/json_fwd.hpp"

namespace Events {
namespace Message {
inline nlohmann::json
createBotHandshake(const std::string &sessionId,
				   const std::string &serverSecret,
				   const std::unique_ptr<BotInfo> &botInfo) {
	nlohmann::json botHandshake;
	botHandshake["type"] = "BotHandshake";
	botHandshake["sessionId"] = sessionId;
	botHandshake["secret"] = serverSecret;
	botHandshake["name"] = botInfo->getName();
	botHandshake["version"] = botInfo->getVersion();
	botHandshake["authors"] = botInfo->getAuthors();
	botHandshake["description"] = botInfo->getDescription();
	botHandshake["homepage"] = botInfo->getHomepage();
	botHandshake["countryCodes"] = botInfo->getCountryCodes();
	botHandshake["gameTypes"] = botInfo->getGametypes();
	botHandshake["platform"] = botInfo->getPlatform();
	botHandshake["programmingLang"] = botInfo->getProgrammingLang();

	return botHandshake;
}

inline nlohmann::json createBotReady() {
	nlohmann::json botReady;
	botReady["type"] = "BotReady";

	return botReady;
}
} // namespace Message
} // namespace Events

#endif
