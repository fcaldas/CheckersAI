/*
 * Human.cpp
 *
 *  Created on: 2 août 2015
 *      Author: Filipe
 */

#include "Human.h"
#include "../Piece.h"
#include <iostream>
using namespace std;

Human::Human(pc_color color, Table *table) : Player(color, table){
	this->loadIMG("./img/selection.png","selection");
	this->loadIMG("./img/moveto.png","moveto");
	selected = false;
	moveSelected = false;

}

move *Human::play(){
	cout << "human play"<<flush;
	if(this->moveSelected == true){
		cout<<"move consumed!"<<flush;
		this->moveSelected = false;
		return this->moveToExecute;
	}else
		return NULL;
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
	}else if(p == NULL){
		if(this->table->isMoveValid(selected_case, pos, this->color) &&
		   this->moveSelected == false){
			this->moveSelected = true;
			moveToExecute = new move;
			moveToExecute->start = selected_case;
			moveToExecute->end = pos;
			cout<<"Move set at player"<<endl;
		}
	}
}


void Human::mouseMove(int x, int y){

}


Human::~Human() {
	// TODO Auto-generated destructor stub
}

