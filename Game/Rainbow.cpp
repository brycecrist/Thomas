#include "Rainbow.h"

Rainbow::Rainbow() {
	initializeColors();
}

void Rainbow::initializeColors() {
	red = Color(237, 26, 26, 100);
	blue = Color(66, 105, 245, 100);
	green = Color(83, 125, 45, 100);
	brown = Color(92, 72, 41, 100);
	white = Color(255, 255, 255, 100);
}