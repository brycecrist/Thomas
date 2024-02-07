#include "Thomas.h"
#include <SDL.h>
#include <iostream>
#include <vector>

Thomas::Thomas() {
	std::cout << "Thomas the Game Engine\n";

	rainbow = Rainbow();

	if (initializeSDL() < 0)
		teardown();
	
	if (createWindow() < 0)
		teardown();

	surface = SDL_GetWindowSurface(window);

	if (surface == NULL)
		teardown();

	player = Player(renderer);
	genesis = Genesis(SCREEN_WIDTH, SCREEN_HEIGHT, STANDARD_TILE_DIMENSION, renderer);

	start();
}

int Thomas::initializeSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error - SDL could not initialize!: " << SDL_GetError();

		return -1;
	}

	return 0;
}

int Thomas::createWindow() {
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		std::cout << "Error - Window could not be created!: " << SDL_GetError();

		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		std::cout << "Error - Renderer could not be created!: " << SDL_GetError();
	}

	return 0;
}

void Thomas::start() {
	// Render textures to the screen
	fillScreen();
	renderWorldTiles();
	renderPlayer();

	// Update renderer
	SDL_RenderPresent(renderer);

	std::cout << "Thomas is up and running\n";

	gameLoop();
}

void Thomas::fillScreen() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void Thomas::gameLoop() {
	auto xVelocity = 0;
	auto yVelocity = 0;

	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e) > 0) {
			lastEvent = e;

			if (e.type == SDL_QUIT)
				quit = true;

			update();
		}

		manageFrame();
	}

	teardown();
}

void Thomas::handleUserMovementInput() {
	// TODO: Record the last pressed key
	auto key = &lastEvent.key;
	auto keySym = key->keysym.sym;
	auto keyEventType = key->type;
	auto keysPressed = SDL_GetKeyboardState(NULL);

	if (keysPressed[SDL_SCANCODE_W]) {
		player.attributes.yVelocity = -player.attributes.speed;
	}

	if (keysPressed[SDL_SCANCODE_S]) {
		player.attributes.yVelocity = player.attributes.speed;
	}

	if (keysPressed[SDL_SCANCODE_A]) {
		player.attributes.xVelocity = -player.attributes.speed;
	}

	if (keysPressed[SDL_SCANCODE_D]) {
		player.attributes.xVelocity = player.attributes.speed;
	}
}

// TODO: take in coordinates
void Thomas::renderPlayer() {
	player.updateXPosition();
	player.updateYPosition();

	SDL_RenderCopy(renderer, player.texture, NULL, &player.sprite);
}

void Thomas::renderTile(Tile tile) {
	SDL_RenderCopy(renderer, tile.texture, NULL, &tile.sprite);
}

void Thomas::renderWorldTiles() {
	const int standardTileDimension = 128;

	for (int i = 0; i < genesis.numOfTilesInY; i++) {
		for (int j = 0; j < genesis.numOfTilesInX; j++) {
			renderTile(genesis.world[i][j]);
		}
	}
}

void Thomas::teardown() {
	std::cout << "Tearing down...\n";
	std::cout << "Printing errors if they exist:\n";
	std::cout << SDL_GetError() << "\n";

	if (window != NULL) 
		SDL_DestroyWindow(window);

	SDL_Quit();
}	

bool Thomas::inRange(int low, int high, int x) {
	return (low <= x && x <= high);
}

void Thomas::render() {
	SDL_RenderClear(renderer);

	renderWorldTiles();
	renderPlayer();

	SDL_RenderPresent(renderer);
}

void Thomas::update() {
	render();

	handleUserMovementInput();

	if (player.moved()) {
		player.updatePositionRelativeToVelocity();
	}
}

void Thomas::manageFrame() {
	frameTime = SDL_GetTicks() - frameStart;

	if (delay > frameTime) {
		SDL_Delay(delay - frameTime);
	}
}
