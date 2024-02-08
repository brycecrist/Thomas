#pragma once
#include <SDL.h>

class Paint {
public:
	SDL_Texture* texture;
	bool isLeftTexture;
	bool isRightTexture;

	Paint();
	Paint(SDL_Texture*, bool isLeftTexture=false, bool isRightTexture=false);
};

