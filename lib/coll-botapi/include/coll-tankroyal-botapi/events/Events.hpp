#ifndef COLL_TANKROYAL_BOTAPI_EVENTS_HPP
#define COLL_TANKROYAL_BOTAPI_EVENTS_HPP

#include <stdexcept>
#include <string>
#include <unordered_map>

#pragma once

namespace Events {
enum class Type {
	Connected,
	ConnectionError,
	Disconnected,

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

namespace DefaultEventPriority {
constexpr const int WON_ROUND = 150;
constexpr const int SKIPPED_TURN = 140;
constexpr const int TICK = 130;
constexpr const int CUSTOM = 120;
constexpr const int TEAM_MESSAGE = 110;
constexpr const int BOT_DEATH = 100;
constexpr const int BULLET_HIT_WALL = 90;
constexpr const int BULLET_HIT_BULLET = 80;
constexpr const int BULLET_HIT_BOT = 70;
constexpr const int BULLET_FIRED = 60;
constexpr const int HIT_BY_BULLET = 50;
constexpr const int HIT_WALL = 40;
constexpr const int HIT_BOT = 30;
constexpr const int SCANNED_BOT = 20;
constexpr const int DEATH = 10;
}; // namespace DefaultEventPriority
}; // namespace Events

#endif
