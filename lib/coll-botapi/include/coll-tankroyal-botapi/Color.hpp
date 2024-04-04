#ifndef COLL_TANKROYAL_BOTAPI_COLOR_HPP
#define COLL_TANKROYAL_BOTAPI_COLOR_HPP

#pragma once

struct Color {
	const char red;
	const char green;
	const char blue;

	Color(char red, char green, char blue)
		: red(red), green(green), blue(blue) {}
};

#endif
