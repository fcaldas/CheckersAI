/*
 * Piece.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef PIECE_H_
#define PIECE_H_

#include "Drawable.h"

class Piece{
private:
	int x, y;
	bool isblack;
public:
	Piece(int x, int y, bool isBlack);

	virtual ~Piece();

	bool isBlack();

	int getX();

	int getY();
};

#endif /* PIECE_H_ */
