/*
 * Table.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Table.h"
#include <iostream>

using namespace std;

Table::Table():Table(WHITE){

}


Table::Table(pc_color colorup) {
	//populate the table
	int row = 0;
	this->color_up = colorup;
	for(int i = 0; i < 12; i++){
		row = i/4;
		int offset = ( row%2 == 1)?0:1;
		if(colorup == WHITE)
			pcWhite.push_back(Piece(offset+(i-row*4)*2, row, true));
		else
			pcBlack.push_back(Piece(offset+(i-row*4)*2, row, true));
	}

	for(int i = 0; i < 12; i++){
		row = i/4;
		int offset = ( row%2 == 1)?1:0;
		if(colorup == WHITE)
			pcBlack.push_back(Piece((i - row * 4)*2 + offset, 5 + row, false));
		else
			pcWhite.push_back(Piece((i - row * 4)*2 + offset, 5 + row, false));
	}

	this->loadIMG("./img/brownblock.bmp", "bblock");
	this->loadIMG("./img/whiteblock.bmp", "wblock");
	this->loadIMG("./img/bpiece.png", "bpiece");
	this->loadIMG("./img/wpiece.png","wpiece");
}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

pc_color Table::getPlayerUp(){
	return this->color_up;
}

Piece* Table::getPiece(position p, pc_color color){
	if(color == WHITE){
		for(int i = 0; i < this->pcWhite.size(); i++){
			if(pcWhite[i].isAtPosition(p))
				return &(pcWhite[i]);
		}
	}else if(color == BLACK){
		for(int i = 0; i < this->pcBlack.size(); i++){
			if(pcBlack[i].isAtPosition(p))
				return &(pcBlack[i]);
		}
	}
	return NULL;
}

void Table::draw(SDL_Surface * screen){
	for(int i = 0; i < 8; i ++){
		bool inv = i%2;
		for(int j = 0; j < 8; j++){
			if(inv){
				this->applySurface(i*60,j*60,"bblock",screen);
			}else{
				this->applySurface(i*60,j*60,"wblock",screen);
			}
			inv = !inv;
		}
	}

	for(int i = 0; i < this->pcBlack.size(); i++){
		this->applySurface(pcBlack[i].getX() * 60, pcBlack[i].getY() * 60,"bpiece",screen);
	}

	for(int i = 0; i < this->pcWhite.size(); i++){
		this->applySurface(pcWhite[i].getX() * 60, pcWhite[i].getY() * 60,"wpiece",screen);
	}

}

gameState Table::executeMove(position &from, position &to, pc_color pcolor){
	//TODO: implement
	return GAME_OK;
}

/* Check if a movement is valid, sends two positions
 * returns bool.
 * assumes white pieces are always at the bottom
 *
 */
bool Table::isMoveValid(position &initial, position &final, pc_color pcolor){
	Piece *toMove = this->getPiece(initial,pcolor);
	bool isKing = toMove->isKing();
	pc_color otherColor = (pcolor == WHITE)?BLACK:WHITE;
	if(toMove == NULL)
		return false;
	bool isLeft = (initial.first > final.first)?true:false;
  	bool hasPieceBetween = false;


	//playing from top
	if(this->getPlayerUp() == pcolor){
		if(isLeft){
			position pLook = initial;
			pLook.first -= 1;
			pLook.second += 1;
			Piece *enemy = this->getPiece(pLook, otherColor);
			if(enemy == NULL &&
			   final.second == pLook.second &&
			   final.first == pLook.first)
				return true;
			else if(enemy != NULL &&
					final.second == pLook.second + 1 &&
					final.first == pLook.first - 1)
				return true;
		}else{
			position pLook = initial;
			pLook.first += 1;
			pLook.second += 1;
			Piece *enemy = this->getPiece(pLook, otherColor);
			if(enemy == NULL &&
			   final.second == pLook.second &&
			   final.first == pLook.first)
				return true;
			else if(enemy != NULL &&
					final.second == pLook.second + 1 &&
					final.first == pLook.first + 1)
				return true;
		}

	}else{
	//playing from bottom
		if(isLeft){
			position pLook = initial;
			pLook.first -= 1;
			pLook.second -= 1;
			Piece *enemy = this->getPiece(pLook, otherColor);
			if(enemy == NULL &&
			   final.second == pLook.second &&
			   final.first == pLook.first)
				return true;
			else if(enemy != NULL &&
					final.second == pLook.second - 1 &&
					final.first == pLook.first - 1)
				return true;
		}else{
			position pLook = initial;
			pLook.first += 1;
			pLook.second -= 1;
			Piece *enemy = this->getPiece(pLook, otherColor);
			if(enemy == NULL &&
			   final.second == pLook.second &&
			   final.first == pLook.first)
				return true;
			else if(enemy != NULL &&
					final.second == pLook.second - 1 &&
					final.first == pLook.first + 1)
				return true;
		}
	}
	//TODO: implement
	return false;
}

