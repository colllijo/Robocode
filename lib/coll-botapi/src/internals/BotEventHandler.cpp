#include "BotEventHandler.hpp"
#include <functional>

BotEventHandler::BotEventHandler(Bot *bot) {
	onConnected->subscribe(
		std::bind(&Bot::onConnected, bot, std::placeholders::_1));
	onDisconnected->subscribe(
		std::bind(&Bot::onDisconnected, bot, std::placeholders::_1));
	onConnectionError->subscribe(
		std::bind(&Bot::onConnectionError, bot, std::placeholders::_1));
}

BotEventHandler::~BotEventHandler() {
	delete onConnected;
	delete onDisconnected;
	delete onConnectionError;

	delete onGameStarted;
	delete onGameEnded;
	delete onGameAborted;
	delete onRoundStarted;
	delete onRoundEnded;
	delete onTick;
	delete onSkippedTurn;
	delete onDeath;
	delete onBotDeath;
	delete onHitBot;
	delete onHitWall;
	delete onBulletFired;
	delete onHitByBullet;
	delete onBulletHitBot;
	delete onBulletHitBullet;
	delete onBulletHitWall;
	delete onScannedBot;
	delete onWonRound;
}
