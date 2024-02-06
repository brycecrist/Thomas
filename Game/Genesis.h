#pragma once
#include "Tile.h"
#include "Rainbow.h"
#include <vector>

class Genesis {
public:
	int numOfTilesInX;
	int numOfTilesInY;
	int standardTileDimension;

	Rainbow rainbow;

	std::vector<std::vector<Tile>> world;

	Genesis();
	Genesis(int screenWidth, int screenHeight, int standardTileDimension, SDL_Renderer* renderer);

	std::vector<std::vector<Tile>> generate(SDL_Renderer* renderer);
};

