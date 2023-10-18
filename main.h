#ifndef PROTEKTOR
#define PROTEKTOR
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
bool init();
bool loadMedia();
void end();
#endif