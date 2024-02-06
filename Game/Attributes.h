#pragma once
class Attributes {
public:
	// Window information
	int xPos = 0;
	int yPos = 0;
	int width = 0;
	int height = 0;

	// Movement
	int speed = 3;
	int xVelocity = 0;
	int yVelocity = 0;
	
	// Color information
	int red = 0;
	int green = 0;
	int blue = 0;
	int alpha = 100;

	Attributes();
	Attributes(int x, int y, int w, int h, int r, int g, int b, int a);
};
