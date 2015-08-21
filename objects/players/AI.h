/*
 * AI.h
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#ifndef AI_H_
#define AI_H_

#include "../Player.h"
#include "../Piece.h"

#include <vector>

class AImove{
public:
	AImove(position from, position to, int score){
		this->score = score;
		m.start = from;
		m.end = to;
	}
	move m;
	int score;

	AImove * previous;
	AImove * next;
};

class AI : public Player {
private:
	Table *table;
	pc_color pcolor;

	bool checkPositionValid(position &p);

public:
	AI(pc_color color, Table *table);

	move * play();

	void draw(SDL_Surface* screen);

	void mouseMove(int x, int y);

	void click(int x, int y);

	virtual ~AI();

	std::vector<AImove> possibleMovesForPiece(Piece *p);
};

#endif /* AI_H_ */
