#ifndef COLL_TANKROYAL_BOTAPI_GAME_SETUP_HPP
#define COLL_TANKROYAL_BOTAPI_GAME_SETUP_HPP

#include <string>

#pragma once

struct GameSetup {
	const std::string gameType;
	const int arenaWidth;
	const int arenaHeight;
	const int numberOfRounds;
	const double gunCoolingRate;
	const int maxInactivityTurns;
	const int turnTimeout;
	const int readyTimeout;

	GameSetup(const std::string &gameType, int arenaWidth, int arenaHeight,
			  int numberOfRounds, double gunCoolingRate, int maxInactivityTurns,
			  int turnTimeout, int readyTimeout)
		: gameType(gameType), arenaWidth(arenaWidth), arenaHeight(arenaHeight),
		  numberOfRounds(numberOfRounds), gunCoolingRate(gunCoolingRate),
		  maxInactivityTurns(maxInactivityTurns), turnTimeout(turnTimeout),
		  readyTimeout(readyTimeout) {
		{}
	}
};

#endif
