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
}

void AI::click(int x, int y){
	//does nothing for AI
	//but has to be declared anyway since its
	//an virtual method of player
}

move * AI::play(){
	return NULL;
}

void AI::draw(SDL_Surface* screen){

}

void AI::mouseMove(int x, int y){

}

AI::~AI() {
	// TODO Auto-generated destructor stub
}


std::vector<AImove> AI::possibleMovesForPiece(Piece *p){
	std::vector<AImove> moveList;
	position pNow(p->getX(),p->getY());
	int dPos = (this->pcolor == table->getPlayerUp())? 1 : -1;

	if(p->isKing()){
		//TODO: logic for king piece
	}else{
		//a piece can only move down until it is a king
		position possible1 = pNow;
		position possible2 = pNow;
		possible1.second += dPos;
		possible2.second += dPos;
		possible1.first -= 1;
		possible2.first += 1;
		if(table->getPieceAt(possible1) == NULL){
			if(this->checkPositionValid(possible1)){
				AImove pMove(pNow, possible1, 0);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible1)->getColor() != this->pcolor ){
			//check next case!
			position possible1C2 = possible1;
			possible1C2.second += dPos;
			possible1C2.first -= 1;
			if(table->getPieceAt(possible1C2) == NULL){
				if(this->checkPositionValid(possible1C2)){
					AImove pMove(pNow, possible1C2, 1);
					moveList.push_back(pMove);
				}
			}
		}


		if(table->getPieceAt(possible2) == NULL){
			if(this->checkPositionValid(possible2)){
				AImove pMove(pNow, possible2, 0);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible2)->getColor() != this->pcolor ){
			//check next case!
			position possible2C2 = possible2;
			possible2C2.second += dPos;
			possible2C2.first += 1;
			if(table->getPieceAt(possible2C2) == NULL){
				if(this->checkPositionValid(possible2C2)){
					AImove pMove(pNow, possible2C2, 1);
					moveList.push_back(pMove);
				}
			}
		}
	}
	return moveList;
}

bool AI::checkPositionValid(position &p){
	if(p.first >= 0 && p.first <= 7 &&
	   p.second >= 0 && p.second <= 7)
		return true;
	return false;
}
