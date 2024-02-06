#include "Player.h"
#include <SDL.h>
#include <iostream>

Player::Player() {
	
}

Player::Player(SDL_Renderer* renderer) {
	sprite = SDL_Rect();
	image = SDL_LoadBMP("Player2.bmp");

	if (image == NULL) {
		std::cout << SDL_GetError() << "\n";
	}

	texture = SDL_CreateTextureFromSurface(renderer, image);

	if (texture == NULL) {
		std::cout << SDL_GetError() << "\n";
	}

	attributes = Attributes(15, 15, 32, 32, 66, 132, 245, 100);

	sprite.x = attributes.xPos;
	sprite.y = attributes.yPos;
	sprite.w = attributes.width;
	sprite.h = attributes.height;

	SDL_FreeSurface(image);
}

// TODO: Add methods to "add" int value or set int value for pos
void Player::updateXPosition() {
	attributes.xPos += attributes.xVelocity;
	sprite.x = attributes.xPos;
}

void Player::updateYPosition() {
	attributes.yPos += attributes.yVelocity;
	sprite.y = attributes.yPos;
}

bool Player::moved() {
	return attributes.xVelocity != 0 || attributes.yVelocity != 0;
}

void Player::resetVelocity() {
	attributes.xVelocity = 0;
	attributes.yVelocity = 0;
}