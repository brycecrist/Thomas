#include "Tile.h"

Tile::Tile() {
	sprite = SDL_Rect();

	image = nullptr;
	texture = nullptr;
	attributes = Attributes(0, 0, 0, 0, 0, 0, 0, 0);
	color = Color(0, 0, 0, 0);
}

Tile::Tile(int x, int y, int w, int h, int r, int g, int b) {
	attributes = Attributes(x, y, w, h, r, g, b, 100);
	sprite = SDL_Rect();
	sprite.x = attributes.xPos;
	sprite.y = attributes.yPos;
	sprite.h = attributes.height;
	sprite.w = attributes.width;
}

Tile::Tile(int x, int y, int w, int h, Color color) {
	attributes = Attributes(x, y, w, h, color.r, color.g, color.b, 100);
	this->color = color;
	sprite = SDL_Rect();
	sprite.x = attributes.xPos;
	sprite.y = attributes.yPos;
	sprite.h = attributes.height;
	sprite.w = attributes.width;
}

Tile::Tile(int x, int y, int w, int h, SDL_Renderer* renderer, const char* bmpName) {
	image = SDL_LoadBMP(bmpName);
	texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_FreeSurface(image);

	attributes = Attributes(x, y, w, h, 0, 0, 0, 0);
	sprite = SDL_Rect();
	sprite.x = attributes.xPos;
	sprite.y = attributes.yPos;
	sprite.h = attributes.height;
	sprite.w = attributes.width;
}