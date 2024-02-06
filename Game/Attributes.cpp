#include "Attributes.h"

Attributes::Attributes() {}

Attributes::Attributes(int x, int y, int w, int h, int r, int g, int b, int a) {
	xPos = x;
	yPos = y;
	width = w;
	height = h;

	red = r;
	green = g;
	blue = b;
	alpha = a;
}