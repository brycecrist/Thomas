#pragma once
#include "Attributes.h"
#include <string>
#include "Color.h"
#include <SDL.h>

class Tile {
public:
	// TODO: Deprecated
	SDL_Rect sprite;

	SDL_Surface* image;
	SDL_Texture* texture;

	Attributes attributes; // TODO: Deprecate rgb info in attributes
	Color color;

	Tile();
	Tile(int x, int y, int w, int h, int r, int g, int b);
	Tile(int x, int y, int w, int h, Color color);
	Tile(int x, int y, int w, int h, SDL_Renderer* renderer, const char* bmpName);
};

