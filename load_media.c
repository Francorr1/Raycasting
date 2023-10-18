#include "main.h"

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
