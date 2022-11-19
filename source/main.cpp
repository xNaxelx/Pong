#include <SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "init failed: " << SDL_GetError();
	}
	else
	{
		std::cout << "init succes";
	}

	return 0;
}