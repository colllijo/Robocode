#ifndef COLL_TANKROYAL_BOTAPI_BOT_EVENTS_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_EVENTS_HPP

#include <vector>

#include "../BotState.hpp"
#include "../BulletState.hpp"
#include "Events.hpp"

#pragma once

namespace Events {
namespace Bot {
struct BotEvent {
	const Type type;
	const int turnNumber;
	const bool critical;

	BotEvent(const Type &type, int turnNumber, bool critical = false)
		: type(type), turnNumber(turnNumber), critical(critical) {}
};

struct BotDeathEvent : public BotEvent {
	const int victimId;

	BotDeathEvent(int turnNumber, int victimId)
		: BotEvent(Type::BotDeathEvent, turnNumber), victimId(victimId) {}
};

struct BulletFiredEvent : public BotEvent {
	const BulletState bullet;

	BulletFiredEvent(int turnNumber, const BulletState &bullet)
		: BotEvent(Type::BulletFiredEvent, turnNumber), bullet(bullet) {}
};

struct BulletHitBotEvent : public BotEvent {
	const int victimId;
	const BulletState bullet;
	const double damage;
	const double energy;

	BulletHitBotEvent(int turnNumber, int victimId, BulletState bullet,
					  double damage, double energy)
		: BotEvent(Type::BulletHitBotEvent, turnNumber), victimId(victimId),
		  bullet(bullet), damage(damage), energy(energy) {}
};

struct BulletHitBulletEvent : public BotEvent {
	const BulletState bullet;
	const BulletState hitBullet;

	BulletHitBulletEvent(int turnNumber, BulletState bullet,
						 BulletState hitBullet)
		: BotEvent(Type::BulletHitBulletEvent, turnNumber), bullet(bullet),
		  hitBullet(hitBullet) {}
};

struct BulletHitWallEvent : public BotEvent {
	const BulletState bullet;

	BulletHitWallEvent(int turnNumber, BulletState bullet)
		: BotEvent(Type::BulletHitWallEvent, turnNumber), bullet(bullet) {}
};

struct DeathEvent : public BotEvent {
	DeathEvent(int turnNumber)
		: BotEvent(Type::BotDeathEvent, turnNumber, true) {}
};

struct HitBotEvent : public BotEvent {
	const int victimId;
	const double energy;
	const double x;
	const double y;
	const bool rammed;

	HitBotEvent(int turnNumber, int victimId, double energy, double x, double y,
				bool rammed)
		: BotEvent(Type::BotHitBotEvent, turnNumber), victimId(victimId),
		  energy(energy), x(x), y(y), rammed(rammed) {}
};

struct HitByBulletEvent : public BotEvent {
	const BulletState bullet;
	const double damage;
	const double energy;

	HitByBulletEvent(int turnNumber, const BulletState &bullet, double damage,
					 double energy)
		: BotEvent(Type::HitByBulletEvent, turnNumber), bullet(bullet),
		  damage(damage), energy(energy) {}
};

struct HitWallEvent : public BotEvent {
	HitWallEvent(int turnNumber)
		: BotEvent(Type::BotHitWallEvent, turnNumber) {}
};

struct ScannedBotEvent : public BotEvent {
	const int scannedByBotId;
	const int scannedBotId;
	const double energy;
	const double x;
	const double y;
	const double direction;
	const double speed;

	ScannedBotEvent(int turnNumber, int scannedByBotId, int scannedBotId,
					double energy, double x, double y, double direction,
					double speed)
		: BotEvent(Type::ScannedBotEvent, turnNumber),
		  scannedByBotId(scannedByBotId), scannedBotId(scannedBotId),
		  energy(energy), x(x), y(y), direction(direction), speed(speed) {}
};

struct SkippedTurnEvent : public BotEvent {
	SkippedTurnEvent(int turnNumber)
		: BotEvent(Type::SkippedTurnEvent, turnNumber, true) {}
};

struct TeamMessageEvent : public BotEvent {
	const void *message;
	const int senderId;

	TeamMessageEvent(int turnNumber, void *message, int senderId)
		: BotEvent(Type::TeamMessageEvent, turnNumber), message(message),
		  senderId(senderId) {}
};

struct TickEvent : public BotEvent {
	const int roundNumber;
	const int enemyCount;
	const BotState botState;
	const std::vector<BulletState> bulletStates;
	const std::vector<BotEvent> events;

	TickEvent(int turnNumber, int roundNumber, int enemyCount,
			  const BotState &botState,
			  const std::vector<BulletState> &bulletStates,
			  const std::vector<BotEvent> &events)
		: BotEvent(Type::TickEventForBot, turnNumber), roundNumber(roundNumber),
		  enemyCount(enemyCount), botState(botState),
		  bulletStates(bulletStates), events(events) {}
};

struct WonRoundEvent : public BotEvent {
	WonRoundEvent(int turnNumber)
		: BotEvent(Type::WonRoundEvent, turnNumber, true) {}
};
}; // namespace Bot
}; // namespace Events

#endif
