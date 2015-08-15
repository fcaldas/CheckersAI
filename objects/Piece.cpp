/*
 * Piece.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Piece.h"

Piece::Piece(int x, int y, bool isBlack) {
	this->x = x;
	this->y = y;
	this->isblack = isBlack;
	this->king = false;
}

Piece::~Piece() {

}

bool Piece::isBlack(){
	return this->isblack;
}

bool Piece::isKing(){
	return king;
}

int Piece::getX(){
	return this->x;
}

int Piece::getY(){
	return this->y;
}

bool Piece::isAtPosition(position p){
	if(getX() == p.first && getY() == p.second)
		return true;
	return false;
}

void Piece::setPosition(position p){
	this->x = p.first;
	this->y = p.second;
}
