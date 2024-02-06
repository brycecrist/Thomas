#include "Color.h"

Color::Color()
{
	r = 255;
	g = 255;
	b = 255;
	a = 100;
}

Color::Color(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}