#ifndef COLL_TANKROYAL_BOTAPI_BOT_EVENT_HANLDER_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_EVENT_HANLDER_HPP

#include <functional>

#include "../Bot.hpp"
#include "../events/BotEvents.hpp"
#include "../events/ConnectionEvents.hpp"
#include "../events/GameEvents.hpp"
#include "EventHandler.hpp"

#pragma once

using namespace Events::Connection;
using namespace Events::Game;
using namespace Events::Bot;

class Bot;
class BotEventHandler {
  public:
	BotEventHandler(Bot *bot);
	~BotEventHandler();

	EventHandler<ConnectedEvent> *onConnected =
		new EventHandler<ConnectedEvent>();
	EventHandler<DisconnectedEvent> *onDisconnected =
		new EventHandler<DisconnectedEvent>();
	EventHandler<ConnectionErrorEvent> *onConnectionError =
		new EventHandler<ConnectionErrorEvent>();

	EventHandler<GameStartedEvent> *onGameStarted =
		new EventHandler<GameStartedEvent>();
	EventHandler<GameEndedEvent> *onGameEnded =
		new EventHandler<GameEndedEvent>();
	EventHandler<GameAbortedEvent> *onGameAborted =
		new EventHandler<GameAbortedEvent>();
	EventHandler<RoundStartedEvent> *onRoundStarted =
		new EventHandler<RoundStartedEvent>();
	EventHandler<RoundEndedEvent> *onRoundEnded =
		new EventHandler<RoundEndedEvent>();
	EventHandler<TickEvent> *onTick = new EventHandler<TickEvent>();
	EventHandler<SkippedTurnEvent> *onSkippedTurn =
		new EventHandler<SkippedTurnEvent>();
	EventHandler<DeathEvent> *onDeath = new EventHandler<DeathEvent>();
	EventHandler<BotDeathEvent> *onBotDeath = new EventHandler<BotDeathEvent>();
	EventHandler<HitBotEvent> *onHitBot = new EventHandler<HitBotEvent>();
	EventHandler<HitWallEvent> *onHitWall = new EventHandler<HitWallEvent>();
	EventHandler<BulletFiredEvent> *onBulletFired =
		new EventHandler<BulletFiredEvent>();
	EventHandler<HitByBulletEvent> *onHitByBullet =
		new EventHandler<HitByBulletEvent>();
	EventHandler<BulletHitBotEvent> *onBulletHitBot =
		new EventHandler<BulletHitBotEvent>();
	EventHandler<BulletHitBulletEvent> *onBulletHitBullet =
		new EventHandler<BulletHitBulletEvent>();
	EventHandler<BulletHitWallEvent> *onBulletHitWall =
		new EventHandler<BulletHitWallEvent>();
	EventHandler<ScannedBotEvent> *onScannedBot =
		new EventHandler<ScannedBotEvent>();
	EventHandler<WonRoundEvent> *onWonRound = new EventHandler<WonRoundEvent>();
};

#endif
