#ifndef		IFUNCTIONS_HPP
# define	IFUNCTIONS_HPP

#include <iostream>
#include "Error.hpp"
#include "Keys.hpp"

#define MIN_WIDTH 200
#define MIN_HEIGHT 200
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define BLOCK_SIZE 20

#define NOTHING 0
#define BODY 1
#define HEAD 2
#define FOOD 3

class IFunctions {
	public:
		virtual void Render(int8_t **arr) = 0;
		virtual void Sleep(unsigned int sleep) = 0;
		virtual Keys Key() = 0;
        virtual bool Event() = 0;
        virtual bool CloseWindow() = 0;
        virtual void Initialise(unsigned int w, unsigned int h) = 0;
		virtual void Color(uint8_t r, uint8_t g, uint8_t b) = 0;
	private:
	
	protected:
		
};

#endif