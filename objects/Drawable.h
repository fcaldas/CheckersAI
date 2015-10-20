/*
 * Drawable.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include <string>
#include <map>
#include <SDL/SDL.h>

using namespace std;

class Drawable {

private:
	map<string, SDL_Surface* > surfaces;

public:

	static SDL_Surface * screen;

	Drawable();

	virtual void draw(SDL_Surface* screen) = 0;

	void loadIMG(string filename, string id);

	void applySurface(int x, int y, string id, SDL_Surface* destination);

	virtual ~Drawable();
};

#endif /* DRAWABLE_H_ */
