#ifndef COLL_TANKROYAL_BOTAPI_BULLET_STATE_HPP
#define COLL_TANKROYAL_BOTAPI_BULLET_STATE_HPP

#include "Color.hpp"

#pragma once

struct BulletState {
	const int bulletId;
	const int ownerId;
	const double power;
	const double x;
	const double y;
	const double direction;
	const Color color;

	BulletState(int bulletId, int ownerId, double power, double x, double y,
				double direction, Color color)
		: bulletId(bulletId), ownerId(ownerId), power(power), x(x), y(y),
		  direction(direction), color(color) {}
};

#endif
