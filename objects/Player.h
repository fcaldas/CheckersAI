/*
 * Player.h
 *
 *  Created on: 26 juil. 2015
 *      Author: filipe
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Table.h"

class Player {
private:
	pc_color color;
	Table *table;
public:
	Player(pc_color color, Table *table);

	~Player();

	virtual void play() = 0;

	bool isMoveValid(position initial, position final);
};

#endif /* PLAYER_H_ */
