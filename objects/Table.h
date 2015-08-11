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
#include <utility>

typedef struct move{
	position start;
	position end;
} move;

enum gameState{GAME_END, GAME_OK, GAME_POINT};

enum pc_color { WHITE, BLACK };

typedef pair<int,int> position;

using namespace std;

class Table : public Drawable{
private:
	vector<Piece> pcWhite, pcBlack;
	pc_color color_up; //check if white pieces are on the upper part
public:
	Table();
	Table(pc_color color_up);
	virtual ~Table();
	void draw(SDL_Surface* screen);
	pc_color getPlayerUp();
	Piece* getPiece(position p, pc_color color);
	gameState executeMove(position &from, position &to, pc_color pcolor);
	bool isMoveValid(position &initial, position &final, pc_color pcolor);
};

#endif /* TABLE_H_ */
