/*
 * Human.cpp
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#include "Human.h"

Human::Human(pc_color color, Table *table) : Player(color, table){
	this->loadIMG("./img/selection.png","selection");
	this->loadIMG("./img/moveto.png","moveto");

}

void Human::play(){

}

void Human::draw(SDL_Surface* screen){

}

void Human::click(int x, int y){

}

Human::~Human() {
	// TODO Auto-generated destructor stub
}

