#include "Player.h"
#include <SDL.h>
#include <iostream>

Player::Player() {
	
}

Player::Player(SDL_Renderer* renderer) {
	// Texture handling
	sprite = SDL_Rect();
	// TODO deprecate
	image = SDL_LoadBMP("Player2.bmp");

	auto playerLeftBMP = SDL_LoadBMP("PlayerLeft");
	auto playerRightBMP = SDL_LoadBMP("PlayerRight");

	auto playerLeftTexture = SDL_CreateTextureFromSurface(renderer, playerLeftBMP);
	auto playerRightTexture = SDL_CreateTextureFromSurface(renderer, playerRightBMP);

	SDL_FreeSurface(playerLeftBMP);
	SDL_FreeSurface(playerRightBMP);

	Paint playerLeftPaint = Paint(playerLeftTexture, true, false);
	Paint playerRightPaint = Paint(playerRightTexture, false, true);

	std::vector<Paint> paintsForAnimation = { playerLeftPaint, playerRightPaint };

	yubaba = Yubaba(paintsForAnimation);

	if (image == NULL) {
		std::cout << SDL_GetError() << "\n";
	}

	texture = SDL_CreateTextureFromSurface(renderer, image);

	if (texture == NULL) {
		std::cout << SDL_GetError() << "\n";
	}


	// Attribute handling
	attributes = Attributes(15, 15, 64, 64, 66, 132, 245, 100);

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

void Player::updatePositionRelativeToVelocity() {
	updateXPosition();
	updateYPosition();
	resetVelocity();
}