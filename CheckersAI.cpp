//============================================================================
// Name        : CheckersAI.cpp
// Author      : Filipe Caldas
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================
// main.cpp
#include <SDL/SDL.h>
#include <string>
#include "utils/sdlfunctions.h"

// Globals:

// Defining screen attributes:
const int sc_width  = 640; // Width
const int sc_height = 480; // Height
const int sc_bpp    = 32;  // Bits per pixel.

// foreground, background, screen
SDL_Surface* fg = NULL, *bg = NULL, *screen = NULL;

// Prototypes:

// Main:
int main(int argc, char* argv[]) {
    // Try to initialize SDL:
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return 1; // SDL is being a bitch and failed to initialize itself. Obviously this is not the programmer's fault.
    }

    // Create the Window :O
    screen = SDL_SetVideoMode(sc_width, sc_height, sc_bpp, SDL_SWSURFACE);

    if (screen == NULL) {
        return 1; // SDL is being a bitch and the screen failed to load :O
    } // Or someone changed the image format from 24-bit.. cough.

    // Set the caption on the screen like a pro:
    SDL_WM_SetCaption("Hi world", NULL);

    // Load a pair of images (24-bit bitmaps)
    fg = loadIMG("hw.bmp");
    bg = loadIMG("bg.bmp");
    // As the images are not 32-bit like the screen, we have to change them to 32-bit
    applySurface(0, 0, bg, screen);
    applySurface(180, 140, fg, screen);

    // Update the screen:
    if (SDL_Flip(screen) == -1) {
        return 1; // The screen failed to be updated...
    }

    SDL_Delay(1000);
    /* I created a variadic function to handle 1 or more surfaces at once.
       The problem is that I haven't finished learning variadic functions yet... */
    FreeIMG(fg);
    FreeIMG(bg);
    // The following could also be used, but when I learn variadic functions properly... ZING.
    // SDL_FreeSurface(fg);
    // SDL_FreeSurface(bg);
    // Sleep for 1 second:
    SDL_Delay(1000);
    // Return 0.
    return 0;
}
