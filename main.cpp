#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>
#include <iostream>
#include "SDL/SDLWrapper.hpp"
#include "GraphicsInterface.hpp"

void dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	/* on Linux, use "./myclass.so" */
	void* handle = dlopen("./SDL/SDL.so", RTLD_LAZY);

	if (!handle)
		dlerror();

	GraphicsInterface* (*create)();
	void (*destroy)(GraphicsInterface*);

	int lib = 1;
	

	if (!(create = (GraphicsInterface* (*)())dlsym(handle, "create")))
		dlerror_wrapper();
	
	if (!(destroy = (void (*)(GraphicsInterface*))dlsym(handle, "destroy")))
		dlerror_wrapper();

	GraphicsInterface* myClass = create();
	myClass->initialize(640, 480);
	int ret = myClass->loop();

	destroy(myClass);
	dlclose(handle);
}