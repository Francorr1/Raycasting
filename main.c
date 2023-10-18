#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init() {

    //init flag
    bool success = true;

    //Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        //Create window
        gWindow = SDL_CreateWindow("This window leaks a lot of memory", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia() {
    //Load success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP("splash.bmp");
    if(gHelloWorld == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
        success = false;
    }
    return success;
}

void end() {
    //Free surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL
    SDL_Quit();
}

int main(int argc, char * args[]){
    //Start SDL and spawn a window
    if(!init()) {
        printf("Failed to spawn window!\n");
    }
    else {
        //Load splash
        if(!loadMedia()) {
            printf("Failed to load splash!\n");
        }
        else {
            //Show the splash
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            //Update surface
            SDL_UpdateWindowSurface(gWindow);
            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
    //Free memory and exit
    end();

    return 0;
}
