#ifndef COLL_TANKROYAL_BOTAPI_BOT_RESULT_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_RESULT_HPP

#pragma once

struct BotResult {
	const int rank;
	const double survival;
	const double lastSurvivorBonus;
	const double bulletDamage;
	const double bulletKillBonus;
	const double ramDamge;
	const double ramKillBonus;
	const double totalScore;
	const int firstPlaces;
	const int secondPlaces;
	const int thridPlaces;

	BotResult(int rank, double survival, double lastSurvivorBonus,
			  double bulletDamage, double bulletKillBonus, double ramDamge,
			  double ramKillBonus, double totalScore, int firstPlaces,
			  int secondPlaces, int thridPlaces)
		: rank(rank), survival(survival), lastSurvivorBonus(lastSurvivorBonus),
		  bulletDamage(bulletDamage), bulletKillBonus(bulletKillBonus),
		  ramDamge(ramDamge), ramKillBonus(ramKillBonus),
		  totalScore(totalScore), firstPlaces(firstPlaces),
		  secondPlaces(secondPlaces), thridPlaces(thridPlaces) {}
};

#endif
