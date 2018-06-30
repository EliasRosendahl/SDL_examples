#include <SDL.h>
#include <iostream>
#include <cstdlib>

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
	//Screen we will be rendrering to
	SDL_Window * window = NULL;
	//Surface contained by window
	SDL_Surface * surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		std::cerr << "could not initialize. Error: " << SDL_GetError();
	}
	else
	{
		window = SDL_CreateWindow("Basic Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cerr << "window could not be created. Error: " << SDL_GetError();
		}
		else
		{
			//Get window surface
			surface = SDL_GetWindowSurface( window );

			//Fill with white
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);

			while (true)
			{
				SDL_Delay(200);
			}
		}
	}
	return 0;
}