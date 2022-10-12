#include "Game.h"

Game::Game(){}
Game::~Game(){}

void Game::Init(const char* title, int xPos, int yPos, int wighth, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		_window = SDL_CreateWindow(title, xPos, yPos, wighth, height, flags);
		
		_renderer = SDL_CreateRenderer(_window, -1, 0);
		if (_renderer)
		{
			SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
		}
		
		_isRunning = true;
	}
	else
	{
		_isRunning = false;
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;


	default:
		break;
	}
}

void Game::Update()
{
	_count++;
}

void Game::Render()
{
	SDL_RenderClear(_renderer);

	SDL_RenderPresent(_renderer); 
}

void Game::Clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}
