/*
 * AI.cpp
 *
 *  Created on: 2 août 2015
 *      Author: filipe
 */

#include "AI.h"
#include <iostream>
#include <queue>

using namespace std;

AI::AI(pc_color color, Table *table) : Player(color, table){
	isPlayerHuman = false;
}

//recursive method to free memory allocated on a tree
void AI::clearTree(vector<AImove *> &tree){
	for(vector<AImove *>::iterator i = tree.begin(); i != tree.end(); i++){
		AImove *m = *i;
		if(m->next.size() != 0)
			clearTree(m->next);
		delete m;
	}
}


void AI::click(int x, int y){
	//does nothing for AI
	//but has to be declared anyway since it's
	//an virtual method of player
}

GameMove * AI::play(){
	vector<AImove *> moveList;
	vector<Piece> *myPieces = getPieces();

	for(int i = 0; i < myPieces->size(); i++){
		vector<AImove *> moves = possibleMovesForPiece(myPieces->at(i), NULL);
		moveList.insert( moveList.end(), moves.begin(), moves.end() );
	}
	//create minimax tree
	vector<AImove *> nowList = moveList;
	vector<AImove *> nextList;
	for(int i = 0; i < this->maxDepth - 1; i++){
		//for each table in this level
		for(int j = 0; j < nowList.size(); j++){
			AImove *m = nowList[j];
			AITable &table = m->tableGame;
			vector<Piece> *myPieces = getPieces(table);
			//go through the pieces and generate a new level of movements
			for(int k = 0; k < myPieces->size(); k++){
				vector<AImove *> moves = possibleMovesForPiece(myPieces->at(k), m);
				nowList[j]->next.insert(nowList[j]->next.end(), moves.begin(), moves.end());
				nextList.insert(nextList.end(), moves.begin(), moves.end() );
			}
		}
		//goes to the next level.
		nowList = nextList;
		std::cout<<"Level:"<<i<<" possibilities:"<<nowList.size()<<std::endl;
		nextList.clear();
	}

	//TODO: return movement from minimax
	cout<<"Size of list = "<<moveList.size()<<endl;
	GameMove *retMove = new GameMove();
	int max = INT32_MIN;
	for(int i = 0; i < moveList.size(); i++){
		if(moveList[i]->score > max){
			retMove->start = moveList[i]->m.start;
			retMove->end = moveList[i]->m.end;
			max = moveList[i]->score;
		}
	}
	this->clearTree(moveList);

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
