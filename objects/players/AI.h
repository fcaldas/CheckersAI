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

using namespace std;

class AImove{
public:
	move m;

	int score;

	AImove * previous;

	vector<AImove *> next;

	AImove(position from, position to, int score, AImove * parent);


	
};

class AI : public Player {
private:
	Table *table;
	pc_color pcolor;
	int maxDepth;
	bool checkPositionValid(position &p);

public:
	AI(pc_color color, Table *table);

	move * play();

	void draw(SDL_Surface* screen);

	void mouseMove(int x, int y);

	void click(int x, int y);

	virtual ~AI();

	std::vector<AImove*> possibleMovesForPiece(Piece &p, AImove &parent);

	AImove* createTree(int treeDepth);
};

#endif /* AI_H_ */
