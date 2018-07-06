all:
	clang++ main.cpp -ldl

sdl:
	@make -C SDL/