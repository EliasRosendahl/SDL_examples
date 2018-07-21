#include "stdafx.h"
#include "Window.h"
#include <SDL.h>
#include <iostream>

const int WIDTH = 640;
const int HEIGHT = 480;

Window::Window()
{
	//Window and surface we'll be rendering to
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;

	//Initialisation
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		std::cerr << "window could not be initialized" << std::endl;
	}
	else
	{
		window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	}
	if (window == NULL)
	{
		std::cerr << "Window could not be created" << std::endl;
	}
	else
	{
		surface = SDL_GetWindowSurface(window);
	}

	surface = SDL_LoadBMP("ART.bmp");
	if(surface == NULL)
	{
		std::cerr << "image could not be loaded" << SDL_GetError() << std::endl;
	}

	SDL_UpdateWindowSurface(window);
}


Window::~Window()
{
}
