/*
 * Piece.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Piece.h"

Piece::Piece(int x, int y, pc_color color) {
	this->x = x;
	this->y = y;
	this->color = color;
	this->king = false;
}

Piece::~Piece() {

}

pc_color Piece::getColor(){
	return this->color;
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

position Piece::getPosition(){
	position p;
	p.first = this->getX();
	p.second = this->getY();
	return p;
}
