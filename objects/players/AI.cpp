/*
 * AI.cpp
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#include "AI.h"

AI::AI(pc_color color, Table *table) : Player(color, table){
	this->table = table;
	this->pcolor = color;
	this->maxDepth = 3;
}


void AI::click(int x, int y){
	//does nothing for AI
	//but has to be declared anyway since it's
	//an virtual method of player
}

move * AI::play(){

	return NULL;
}

void AI::draw(SDL_Surface* screen){
	
}

void AI::mouseMove(int x, int y){


}


AImove* AI::createTree(int treeDepth){
	AImove* gameTree;
	bool aiPlay = true;
	for(int i = 0; i < treeDepth; i++){

		//vector<Piece> &pieces;
		
		
		//flip player
		aiPlay = !aiPlay;
	}

	return gameTree;
}

AI::~AI() {
	// TODO Auto-generated destructor stub
	
}

bool AI::checkPositionValid(position &p){
	if(p.first >= 0 && p.first <= 7 &&
	   p.second >= 0 && p.second <= 7)
		return true;
	return false;
}
