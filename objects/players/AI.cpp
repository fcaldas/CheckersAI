/*
 * AI.cpp
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#include "AI.h"
#include <iostream>
using namespace std;

AI::AI(pc_color color, Table *table) : Player(color, table){
	this->maxDepth = 3;
	isPlayerHuman = false;
}


void AI::click(int x, int y){
	//does nothing for AI
	//but has to be declared anyway since it's
	//an virtual method of player
}

move * AI::play(){
	vector<AImove *> moveList;
	vector<Piece> *myPieces = getPieces();

	for(int i = 0; i < myPieces->size(); i++){
		vector<AImove *> moves = possibleMovesForPiece(myPieces->at(i), NULL);
		moveList.insert( moveList.end(), moves.begin(), moves.end() );
	}
	//TODO:

	//generate tree

	//apply minimax

	//return movement from minimax
	cout<<"Size of list = "<<moveList.size()<<endl;
	move *retMove = new move();
	int max = INT32_MIN;
	for(int i = 0; i < moveList.size(); i++){
		if(moveList[i]->score > max){
			retMove->start = moveList[i]->m.start;
			retMove->end = moveList[i]->m.end;
			max = moveList[i]->score;
		}
		delete moveList[i];
	}

	return retMove;
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
