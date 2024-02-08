#pragma once
#include "Paint.h"
#include <vector>
#include <SDL.h>

class Yubaba {
public:
	Yubaba();
	Yubaba(std::vector<Paint> textures);

	Paint currentTexture;
	std::vector<Paint> textures;

	bool movedLeft;
	bool movedRight;

	void animateLeft();
	void animateRight();
};

