#ifndef COLL_TANKROYAL_BOTAPI_BOT_STATE_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_STATE_HPP

#include "Color.hpp"
struct BotState {
	const bool isDroid;
	const double energy;
	const double x;
	const double y;
	const double direction;
	const double gunDirection;
	const double radarDirection;
	const double radarSweep;
	const double speed;
	const double turnRate;
	const double gunTurnRate;
	const double radarTurnRate;
	const double gunHeat;
	const Color bodyColor;
	const Color turretColor;
	const Color radarColor;
	const Color bulletColor;
	const Color scanColor;
	const Color tracksColor;
	const Color gunColor;

	BotState(bool isDroid, double energy, double x, double y, double direction,
			 double gunDirection, double radarDirection, double radarSweep,
			 double speed, double turnRate, double gunTurnRate,
			 double radarTurnRate, double gunHeat, const Color &bodyColor,
			 const Color &turretColor, const Color &radarColor,
			 const Color &bulletColor, const Color &scanColor,
			 const Color &tracksColor, const Color &gunColor)
		: isDroid(isDroid), energy(energy), x(x), y(y), direction(direction),
		  gunDirection(gunDirection), radarDirection(radarDirection),
		  radarSweep(radarSweep), speed(speed), turnRate(turnRate),
		  gunTurnRate(gunTurnRate), radarTurnRate(radarTurnRate),
		  gunHeat(gunHeat), bodyColor(bodyColor), turretColor(turretColor),
		  radarColor(radarColor), bulletColor(bulletColor),
		  scanColor(scanColor), tracksColor(tracksColor), gunColor(gunColor) {}
};

#endif
