#include "Genesis.h"

Genesis::Genesis() {
	numOfTilesInX = 0;
	numOfTilesInY = 0;
	standardTileDimension = 0;
	rainbow = Rainbow();
}

Genesis::Genesis(int screenWidth, int screenHeight, int standardTileDimension, SDL_Renderer* renderer) {
	this->standardTileDimension = standardTileDimension;
	numOfTilesInX = screenWidth / standardTileDimension;
	numOfTilesInY = screenHeight / standardTileDimension;

	rainbow = Rainbow();

	world = generate(renderer);
}

std::vector<std::vector<Tile>> Genesis::generate(SDL_Renderer* renderer) {
	std::vector<std::vector<Tile>> worldMap = {};

	for (int i = 0; i < numOfTilesInY; i++) {
		std::vector<Tile> vector = {};
		for (int j = 0; j < numOfTilesInX; j++) {

			// TODO: Replace with actual world gen logic
			// TODO: Get rid of colors
			Color color;
			if (j % 2)
				color = rainbow.green;
			else
				color = rainbow.brown;

			const char* bmp = "Grass.bmp";

			auto tile = Tile(j * standardTileDimension, i * standardTileDimension, standardTileDimension, standardTileDimension, 
				renderer, bmp);

			vector.push_back(tile);
		}
		worldMap.push_back(vector);
	}

	return worldMap;
}