/*
 * Table.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef TABLE_H_
#define TABLE_H_

#include "../utils/sdlfunctions.h"
#include "Drawable.h"
#include <vector>
#include "Piece.h"

using namespace std;

class Table : public Drawable{
private:
	vector<Piece> pcWhite, pcBlack;

public:
	Table();
	virtual ~Table();
	void draw(SDL_Surface* screen);
};

#endif /* TABLE_H_ */
