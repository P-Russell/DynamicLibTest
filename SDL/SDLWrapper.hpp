#ifndef __SDLWRAPPER_HPP__
#define __SDLWRAPPER_HPP__

#include "../GraphicsInterface.hpp"
#include "include/SDL.h"

class SDLWrapper: public GraphicsInterface {

public:
	SDLWrapper(void);
	~SDLWrapper(void);
	virtual int initialize(int width, int height);
	virtual void wait(int milliseconds);
	virtual int loop();
private:
	SDL_Window *window;
};

#endif