#include "Paint.h"

Paint::Paint() {}

Paint::Paint(SDL_Texture* texture, bool isLeftTexture, bool isRightTexture) {
	this->texture = texture;
	this->isLeftTexture = isLeftTexture;
	this->isRightTexture = isRightTexture;
}