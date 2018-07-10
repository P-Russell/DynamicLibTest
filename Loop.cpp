/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 08/24/37 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/04 08/24/37 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Loop.hpp"
#include <dlfcn.h>
#include <string>

Loop::Loop() {}

Loop::Loop(Loop const & src) {
	*this = src;	
}

Loop::~Loop() {}

Loop & Loop::operator=(Loop const & src)
{
	if (this != &src)
    {
		*this = src;
    }
	return (*this);
}

void Loop::GameLoop(void)
{
	void *dl;
	//dl = dlopen("sfml/libsfml.dylib", RTLD_LAZY);
	//dl = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
	dl = dlopen("opengl/libog.dylib", RTLD_LAZY);
	std::cout << "dl open\n";
	if (!dl)
		LibError();
	
	IFunctions *(*functions)(void);
	functions = (IFunctions *(*)()) dlsym(dl, "createFunctions");
	std::cout << "create\n";
	if (!functions)
	{
		LibError();
	}
	
	IFunctions * func;
	func = functions();
	func->Initialise(200, 200);
	//int8_t arr[200/BLOCK_SIZE][200/BLOCK_SIZE];
	for (int i = 0; i < 200/BLOCK_SIZE; i++)
	{
		for (int j = 0; j < 200/BLOCK_SIZE; j++)
		{
	//		arr[i][j] = NOTHING;
		}
	}
	//arr[2][2] = BODY;
	//arr[3][3] = HEAD;
	//arr[4][4] = FOOD;
	while (true)
	{
		if (func->Event())
		{
			if (func->CloseWindow())
				break;
			else if (func->Key() == Escape_Key)
				break;
			else if (func->Key() == W_Key)
				func->Color(255, 0, 0);
			else if (func->Key() == A_Key)
				func->Color(0, 255, 0);
			else if (func->Key() == S_Key)
				func->Color(0, 0, 255);
			else if (func->Key() == D_Key)
				func->Color(255, 0, 255);
		}
	}
	void  (*dest)(IFunctions *);
	dest = (void(*)(IFunctions *))dlsym(dl, "deleteFunctions");
	std::cout << "delete\n";
	if (!dest)
	{
		LibError();
	}
	dest(func);
}

void Loop::LibError(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void Loop::LibError(std::string & s)
{
	std::cerr << "Error: " << s << std::endl;
	exit(EXIT_FAILURE);
}
