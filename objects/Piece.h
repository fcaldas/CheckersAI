/*
 * Piece.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef PIECE_H_
#define PIECE_H_
#include <utility>
#include "Drawable.h"

typedef pair<int,int> position;

class Piece{
private:
	int x, y;
	bool isblack;
	bool king;
public:
	Piece(int x, int y, bool isBlack);

	virtual ~Piece();

	bool isBlack();

	int getX();

	int getY();

	bool isAtPosition(position p);

	void setPosition(position p);

	bool isKing();
};

#endif /* PIECE_H_ */
