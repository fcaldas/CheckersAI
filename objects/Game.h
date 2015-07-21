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

class Game {
public:

	Game();
	virtual ~Game();

	void Draw();

};

#endif /* GAME_H_ */
