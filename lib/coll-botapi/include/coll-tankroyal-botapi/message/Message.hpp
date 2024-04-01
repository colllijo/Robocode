#ifndef COLL_TANKROYAL_BOTAPI_MESSAGE_HPP
#define COLL_TANKROYAL_BOTAPI_MESSAGE_HPP

#include <stdexcept>
#include <string>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include "../BotInfo.hpp"

namespace Message {
enum class Type {
	BotHandshake,
	ControllerHandshake,
	ObserverHandshake,
	ServerHandshake,

	BotReady,
	BotIntent,
	BotInfo,
	BotListUpdate,

	GameStartedEventForBot,
	GameStartedEventForObserver,
	GameEndedEventForBot,
	GameEndedEventForObserver,
	GameAbortedEvent,
	GamePausedEventForObserver,
	GameResumedEventForObserver,

	RoundStartedEvent,
	RoundEndedEventForBot,
	RoundEndedEventForObserver,

	ChangeTps,
	TpsChangedEvent,

	BotDeathEvent,
	BotHitBotEvent,
	BotHitWallEvent,
	BulletFiredEvent,
	BulletHitBotEvent,
	BulletHitBulletEvent,
	BulletHitWallEvent,
	HitByBulletEvent,
	ScannedBotEvent,
	SkippedTurnEvent,
	TickEventForBot,
	TickEventForObserver,
	WonRoundEvent,
	TeamMessageEvent,

	StartGame,
	StopGame,
	PauseGame,
	ResumeGame,
	NextTurn,
};
static const std::unordered_map<std::string, Type> typeMap = {
	{"BotHandshake", Type::BotHandshake},
	{"ControllerHandshake", Type::ControllerHandshake},
	{"ObserverHandshake", Type::ObserverHandshake},
	{"ServerHandshake", Type::ServerHandshake},

	{"BotReady", Type::BotReady},
	{"BotIntent", Type::BotIntent},
	{"BotInfo", Type::BotInfo},
	{"BotListUpdate", Type::BotListUpdate},

	{"GameStartedEventForBot", Type::GameStartedEventForBot},
	{"GameStartedEventForObserver", Type::GameStartedEventForObserver},
	{"GameEndedEventForBot", Type::GameEndedEventForBot},
	{"GameEndedEventForObserver", Type::GameEndedEventForObserver},
	{"GameAbortedEvent", Type::GameAbortedEvent},
	{"GamePausedEventForObserver", Type::GamePausedEventForObserver},
	{"GameResumedEventForObserver", Type::GameResumedEventForObserver},

	{"RoundStartedEvent", Type::RoundStartedEvent},
	{"RoundEndedEventForBot", Type::RoundEndedEventForBot},
	{"RoundEndedEventForObserver", Type::RoundEndedEventForObserver},

	{"ChangeTps", Type::ChangeTps},
	{"TpsChangedEvent", Type::TpsChangedEvent},

	{"BotDeathEvent", Type::BotDeathEvent},
	{"BotHitBotEvent", Type::BotHitBotEvent},
	{"BotHitWallEvent", Type::BotHitWallEvent},
	{"BulletFiredEvent", Type::BulletFiredEvent},
	{"BulletHitBotEvent", Type::BulletHitBotEvent},
	{"BulletHitBulletEvent", Type::BulletHitBulletEvent},
	{"BulletHitWallEvent", Type::BulletHitWallEvent},
	{"HitByBulletEvent", Type::HitByBulletEvent},
	{"ScannedBotEvent", Type::ScannedBotEvent},
	{"SkippedTurnEvent", Type::SkippedTurnEvent},
	{"TickEventForBot", Type::TickEventForBot},
	{"TickEventForObserver", Type::TickEventForObserver},
	{"WonRoundEvent", Type::WonRoundEvent},
	{"TeamMessageEvent", Type::TeamMessageEvent},

	{"StartGame", Type::StartGame},
	{"StopGame", Type::StopGame},
	{"PauseGame", Type::PauseGame},
	{"ResumeGame", Type::ResumeGame},
	{"NextTurn", Type::NextTurn}};

inline Type typeFromString(const std::string type) {
	auto iter = typeMap.find(type);
	if (iter != typeMap.end())
		return iter->second;
	else
		throw std::invalid_argument("Invalid Type string.");
}

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
} // namespace Message

#endif
