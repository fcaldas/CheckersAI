#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Drawable.h"
#include <iostream>

using namespace std;

SDL_Surface * Drawable::screen;

void Drawable::loadIMG(string filename, string id) {
    if(surfaces.find(id) != surfaces.end()){
    	cout<<"Image "<<id<<" already loaded"<<endl;
    	return;
    }
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if(loadedSurface == NULL){
    	cout<<SDL_GetError()<<flush<<endl;

    }
    surfaces[id] = loadedSurface;// optimizedSurface;
    return ;
}

void Drawable::applySurface(int x, int y, string id, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    // Blit the surface:
    SDL_BlitSurface(surfaces[id], NULL, destination, &offset);
}

Drawable::Drawable(){
	std::cout<<"Calling drawable() again!!!!"<<std::endl<<std::flush;
}

Drawable::~Drawable(){
	//clean memory
	for(map<string, SDL_Surface*>::iterator it = surfaces.begin(); it != surfaces.end(); it++){
		if(it->second != NULL)
			SDL_FreeSurface(it->second);
	}

}
