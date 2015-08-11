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
#include "players/AI.h"
#include "players/Human.h"

class Game : Drawable{
private:
	Table table;
	int clickX, clickY;
	Player *player_white;
	Player *player_black;
	pc_color active_player;
public:

	Game();

	virtual ~Game();

	void draw(SDL_Surface *screen);

	void click(int x, int y);

	void play();

	void mouseMove(int x, int y);
};

#endif /* GAME_H_ */
