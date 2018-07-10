#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>
#include <iostream>
#include "IFunctions.hpp"

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

	IFunctions* (*create)();
	void (*destroy)(IFunctions*);

	int lib = 1;
	

	if (!(create = (IFunctions* (*)())dlsym(handle, "create")))
		dlerror_wrapper();
	
	if (!(destroy = (void (*)(IFunctions*))dlsym(handle, "destroy")))
		dlerror_wrapper();

	IFunctions* myClass = create();

	myClass->Initialise(600, 600);
	myClass->Sleep(3000);

	destroy(myClass);
	dlclose(handle);
}