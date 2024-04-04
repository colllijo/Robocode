#ifndef COLL_TANKROYAL_BOTAPI_GAME_EVENTS_HPP
#define COLL_TANKROYAL_BOTAPI_GAME_EVENTS_HPP

#include "../BotResult.hpp"
#include "../GameSetup.hpp"
#include "Events.hpp"

#pragma once

namespace Events {
namespace Game {
struct GameStartedEvent {
	const Type type;
	const int myId;
	const GameSetup gameSetup;

	GameStartedEvent(int myId, const GameSetup &gameSetup)
		: type(Type::GameStartedEventForBot), myId(myId), gameSetup(gameSetup) {
	}
};

struct GameEndedEvent {
	const Type type;
	const int numberOfRounds;
	const BotResult result;

	GameEndedEvent(int numberOfRounds, const BotResult &result)
		: type(Type::GameEndedEventForBot), numberOfRounds(numberOfRounds),
		  result(result) {}
};

struct GameAbortedEvent {
	const Type type;

	GameAbortedEvent() : type(Type::GameAbortedEvent) {}
};

struct RoundStartedEvent {
	const Type type;
	const int roundNumber;

	RoundStartedEvent(int roundNumber)
		: type(Type::RoundStartedEvent), roundNumber(roundNumber) {}
};

struct RoundEndedEvent {
	const Type type;
	const int roundNumber;
	const int turnNumber;
	const BotResult result;

	RoundEndedEvent(int roundNumber, int turnNumber, const BotResult &result)
		: type(Type::RoundEndedEventForBot), roundNumber(roundNumber),
		  turnNumber(turnNumber), result(result) {}
};
}; // namespace Game
}; // namespace Events

#endif
