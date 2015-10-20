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
#include "Utils.h"

typedef pair<int,int> position;

class Piece{
	friend class TableBase;
private:

	int x, y;
	pc_color color;
	bool king;
public:
	Piece(int x, int y, pc_color color);

	virtual ~Piece();

	pc_color getColor();

	int getX();

	int getY();

	bool isAtPosition(position p);

	void setPosition(position p);

	position getPosition();

	bool isKing();
};

#endif /* PIECE_H_ */
