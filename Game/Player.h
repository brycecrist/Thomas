#pragma once
#include "Attributes.h"
#include <SDL.h>

class Player {
public:
	// TODO: Sprites
	// TODO: Deprecated sprite
	SDL_Rect sprite; // TODO: Get actual sprites

	SDL_Surface* image;
	SDL_Texture* texture;
	Attributes attributes;

	Player();
	Player(SDL_Renderer* renderer);

	void updateXPosition();
	void updateYPosition();
	bool moved();
	void resetVelocity();
};

