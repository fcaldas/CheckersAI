/*
 * Piece.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef PIECE_H_
#define PIECE_H_

#include "Drawable.h"

class Piece : public Drawable {
private:
	int x, y;

public:
	Piece(int x, int y);

	virtual ~Piece();

	void draw(SDL_Surface* screen);
};

#endif /* PIECE_H_ */
