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
	//but has to be declared anyway since it's
	//an virtual method of player
}

move * AI::play(){


	move * decision = new move();
	return move;
}

void AI::draw(SDL_Surface* screen){
	
}

void AI::mouseMove(int x, int y){


}


vector<AImove*> AI::createTree(int treeDepth){
	vector<AImove*> gameTree;
	bool aiPlay = true;
	for(int i = 0; i < treeDepth; i++){
		vector<Piece> &pieces;
		
		
		//flip player
		aiPlay = !aiPlay;
	}

	return gameTree;
}

AI::~AI() {
	// TODO Auto-generated destructor stub
	
}

vector<AImove *> AI::possibleMovesForPiece(Piece &p, AImove &parent){

	vector<AImove *> moveList;
	pc_color pieceColor = p.getColor();
	position pNow(p.getX(),p.getY());
		
	int dPos = (pieceColor == table->getPlayerUp())?1:-1;
	int dScore = (this->pcolor == pieceColor)?1:-1;
	
	if(p->isKing()){
		//TODO: logic for king
	}else{
		//TODO: a piece can only move down until it is a king
		position possible1 = pNow;
		position possible2 = pNow;
		possible1.second += dPos;
		possible2.second += dPos;
		possible1.first -= 1;
		possible2.first += 1;
		if(table->getPieceAt(possible1) == NULL){
			if(this->checkPositionValid(possible1)){
				AImove *  pMove = new AImove(pNow, possible1, 0, &parent);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible1)->getColor() != this->pcolor ){
			//check next case!
			position possible1C2 = possible1;
			possible1C2.second += dPos;
			possible1C2.first -= 1;
			if(table->getPieceAt(possible1C2) == NULL){
				if(this->checkPositionValid(possible1C2)){
					AImove *pMove = new AImove(pNow, possible1C2, 1 * dScore, &parent);
					moveList.push_back(pMove);
				}
			}
		}


		if(table->getPieceAt(possible2) == NULL){
			if(this->checkPositionValid(possible2)){
				AImove * pMove = new AImove(pNow, possible2,0, parent);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible2)->getColor() != this->pcolor ){
			//check next case!
			position possible2C2 = possible2;
			possible2C2.second += dPos;
			possible2C2.first += 1;
			if(table->getPieceAt(possible2C2) == NULL){
				if(this->checkPositionValid(possible2C2)){
					AImove * pMove = new AImove(pNow, possible2C2, 1 * dScore, parent);
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
