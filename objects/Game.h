/*
 * Game.h
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#ifndef GAME_H_
#define GAME_H_
#include <SDL/SDL.h>

#include "Table.h"
#include "Piece.h"
#include "Player.h"

class Game : Drawable{
private:
	Table table;
	int clickX, clickY;
	Player *player1;
	Player *player2;
public:

	Game();
	virtual ~Game();

	void draw(SDL_Surface *screen);

	void click(int x, int y);
};

#endif /* GAME_H_ */
