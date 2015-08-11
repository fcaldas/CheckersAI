/*
 * AI.h
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#ifndef AI_H_
#define AI_H_

#include "../Player.h"

class AI : public Player {
public:
	AI(pc_color color, Table *table);

	move * play();

	void draw(SDL_Surface* screen);

	void mouseMove(int x, int y);

	void click(int x, int y);

	virtual ~AI();
};

#endif /* AI_H_ */
