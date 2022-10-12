#pragma once

#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xPos, int yPos, int wighth, int height, bool fullscreen);
	
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return _isRunning; }

private:
	int _count = 0;
	bool _isRunning;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

