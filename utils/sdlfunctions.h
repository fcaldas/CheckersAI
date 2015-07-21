/*
 * sdlfunctions.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef SDLFUNCTIONS_H_
#define SDLFUNCTIONS_H_

#include <SDL/SDL.h>
#include <string>

SDL_Surface* loadIMG(std::string); // Loads an image to the screen
void applySurface(int, int, SDL_Surface*, SDL_Surface*); // Applies image, but does not refresh screen
void FreeIMG(SDL_Surface*, ...); // Clears an image


#endif /* SDLFUNCTIONS_H_ */
