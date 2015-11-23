/*
 * Human.h
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "../Player.h"

class Human : public Player {
	position selected_case;
	bool selected;
	bool moveSelected;
	GameMove *moveToExecute;
public:
	Human(pc_color color, Table *table);

	GameMove *play();

	void draw(SDL_Surface* screen);

	void click(int x, int y);

	void mouseMove(int x, int y);

	virtual ~Human();
};

#endif /* HUMAN_H_ */
