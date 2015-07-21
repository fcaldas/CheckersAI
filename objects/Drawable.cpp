#include <SDL/SDL.h>
#include "Drawable.h"


void Drawable::loadIMG(string filename, string id) {
    SDL_Surface* temp = SDL_LoadBMP(filename.c_str()); // Load the image
    SDL_Surface* surface = NULL;
    //never reload
    if(surfaces.count(id) == true)
    	return;
    if (temp) { // If temp != 0, the image loaded successfully.
        surface = SDL_DisplayFormat(temp); // Format the image correctly (32 bit instead of 24 bit)
        SDL_FreeSurface(temp); // Free the temporary surface from memory.
    }
    surfaces[id] = surface;
    return; // Return the hopefully successfully loaded surface
}

void Drawable::applySurface(int x, int y, string id, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    // Blit the surface:
    SDL_BlitSurface(surfaces[id], NULL, destination, &offset);
}

Drawable::~Drawable(){
	//clean memory
	for(map<string, SDL_Surface*>::iterator it = surfaces.begin();
		it != surfaces.end(); it++){
		if(it->second != NULL)
			SDL_FreeSurface(it->second);
	}

}
