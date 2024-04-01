#ifndef COLL_TANKROYAL_BOTAPI_BOT_EVENT_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_EVENT_HPP

#pragma once

class BotEvent {
  public:
	const int turnNumber;

	int getTurnNumber() const { return turnNumber; }
	bool isCritical() const { return false; }

  protected:
	BotEvent(int trunNumber) : turnNumber(turnNumber) {}
};

#endif
