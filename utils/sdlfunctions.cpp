
#include "sdlfunctions.h"

SDL_Surface* loadIMG(std::string filename) {
    SDL_Surface* temp = SDL_LoadBMP(filename.c_str()); // Load the image
    SDL_Surface* surface = NULL;

    if (temp) { // If temp != 0, the image loaded successfully.
        surface = SDL_DisplayFormat(temp); // Format the image correctly (32 bit instead of 24 bit)
        SDL_FreeSurface(temp); // Free the temporary surface from memory.
    }

    return surface; // Return the hopefully successfully loaded surface
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    // Blit the surface:
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void FreeIMG(SDL_Surface* surf, ...) {
    if (surf != NULL) {
        SDL_FreeSurface(surf);
    }
}
