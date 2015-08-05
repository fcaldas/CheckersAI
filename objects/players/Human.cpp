/*
 * Human.cpp
 *
 *  Created on: 2 août 2015
 *      Author: Filipe
 */

#include "Human.h"
#include "../Piece.h"

Human::Human(pc_color color, Table *table) : Player(color, table){
	this->loadIMG("./img/selection.png","selection");
	this->loadIMG("./img/moveto.png","moveto");

}

void Human::play(){

}

void Human::draw(SDL_Surface* screen){
	if(selected)
		this->applySurface(selected_case.first * 60,
				  	  	   selected_case.second * 60,
				  	  	   "selection", screen);
}

void Human::click(int x, int y){
	position pos;
	pos.first = x;
	pos.second = y;
	Piece *p = table->getPiece(pos, this->color);
	if(p != NULL){
		this->selected = true;
		selected_case = pos;
	}
}


void Human::mouseMove(int x, int y){

}


Human::~Human() {
	// TODO Auto-generated destructor stub
}

