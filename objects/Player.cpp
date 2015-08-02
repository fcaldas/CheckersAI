/*
 * Player.cpp
 *
 *  Created on: 26 juil. 2015
 *      Author: filipe
 */

#include "Player.h"
#include "Table.h"

#include <iostream>

using namespace std;

Player::Player(pc_color color, Table *table) {
	this->table = table;
	this->color = color;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

/* Check if a movement is valid, sends two positions
 * returns bool.
 * assumes white pieces are always at the bottom
 *
 */
bool Player::isMoveValid(position initial, position final){
	Piece *toMove = table->getPiece(initial,this->color);
	bool isKing = toMove->isKing();
	pc_color otherColor = (this->color == WHITE)?BLACK:WHITE;
	if(toMove == NULL)
		return false;
	bool isLeft = (initial.first > final.first)?true:false;
  	bool hasPieceBetween = false;


	//playing from top
	if(table->getPlayerUp() == this->color){
		if(isLeft){
			position pLook = initial;
			pLook.first -= 1;
			pLook.second += 1;
			Piece *enemy = table->getPiece(pLook, otherColor);
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
			Piece *enemy = table->getPiece(pLook, otherColor);
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
			Piece *enemy = table->getPiece(pLook, otherColor);
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
			Piece *enemy = table->getPiece(pLook, otherColor);
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

