#pragma once
#include "Player.h"
#include "Tile.h"
#include "Rainbow.h"
#include "Genesis.h"
#include <SDL.h>

class Thomas {
public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 640;
	const int STANDARD_TILE_DIMENSION = 64;

	const int FPS = 60;
	const int delay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	Rainbow rainbow;
	Genesis genesis;

	// Entities:
	Player player;

	// Events:
	SDL_Event lastEvent;
		
	Thomas();

	int initializeSDL();
	int createWindow();
	void start();
	void fillScreen();
	void gameLoop();
	void handleUserMovementInput();
	void renderPlayer();
	void renderTile(Tile tile);
	void renderWorldTiles();
	void update();
	void render();
	void teardown();
	void manageFrame();
	bool inRange(int low, int high, int x);
};
