//============================================================================
// Name        : CheckersAI.cpp
// Author      : Filipe Caldas
// Version     :
//============================================================================
// main.cpp
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "objects/Drawable.h"
#include "utils/sdlfunctions.h"
#include "objects/Game.h"

#include <iostream>

using namespace std;
// Globals:

// foreground, background, screen
SDL_Surface* fg = NULL, *bg = NULL, *screen = NULL;

const Uint32 fps = 40;
const Uint32 minframetime = 1000 / fps;
// Main:
int main(int argc, char* argv[]) {
    // Try to initialize SDL:
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return 1; // SDL is being a bitch and failed to initialize itself. Obviously this is not the programmer's fault.
    }

    // Create the Window :O
    screen = SDL_SetVideoMode(480,480,32,SDL_SWSURFACE);

    Drawable::screen = screen;

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if( initted & flags != flags) {
        cout<<"could not init SDL_Image" << endl;
        cout<<"Reason: " << IMG_GetError() << endl;
    }

    if (screen == NULL) {
        return 1; // SDL is being a bitch and the screen failed to load :O
    } // Or someone changed the image format from 24-bit.. cough.

    // Set the caption on the screen like a pro:
    SDL_WM_SetCaption("CheckersAI", NULL);


    // As the images are not 32-bit like the screen, we have to change them to 32-bit
    applySurface(0, 0, bg, screen);
    applySurface(180, 140, fg, screen);

    // Update the screen:
    if (SDL_Flip(screen) == -1) {
        return 1; // The screen failed to be updated...
    }

    Game game;
    bool running = true;
    SDL_Event event;
    Uint32 frametime;

    while (running)
    {

      frametime = SDL_GetTicks ();

      while (SDL_PollEvent (&event) != 0)
      {
			switch (event.type)
			{
			  case SDL_QUIT:    running = false;
								break;
			  case SDL_MOUSEBUTTONDOWN:
								game.click(event.button.x, event.button.y);
								break;
			  case SDL_MOUSEMOTION:
				  	  	  	  	game.mouseMove(event.motion.x, event.motion.y);
				  	  	  	  	break;
			}
      }

      if (SDL_GetTicks () - frametime < minframetime)
        SDL_Delay (minframetime - (SDL_GetTicks () - frametime));
      game.play();
      game.draw(screen);
      SDL_Flip( screen );

    }

    // Return 0.
    return 0;
}
