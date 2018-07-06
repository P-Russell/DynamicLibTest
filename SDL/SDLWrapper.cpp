#include <iostream>
#include "include/SDL.h"
#include "SDLWrapper.hpp"

SDLWrapper::SDLWrapper() {}

SDLWrapper::~SDLWrapper()
{
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

int SDLWrapper::initialize(int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);

	this->window = SDL_CreateWindow(
		"An SDL2 window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return 1;
	}

	return 0;
}

int SDLWrapper::loop()
{
	bool gameRunning = true;
	SDL_Event event;
	while (gameRunning)
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
			else
				switch (event.key.keysym.sym) {
					case SDL_QUIT:
						gameRunning = false;
						break ;
					case SDLK_1:
						return 1;
					case SDLK_2:
						return 2;
					case SDLK_3:
						return 3;
			}
		}
	return 0;
}

void SDLWrapper::wait(int milliseconds)
{
	SDL_Delay(milliseconds);
}

extern "C" GraphicsInterface *create()
{
	return new SDLWrapper;
}

extern "C" void destroy(GraphicsInterface *wrapper)
{
	delete wrapper;
}