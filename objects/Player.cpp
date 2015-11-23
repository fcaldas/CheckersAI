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

pc_color Player::getColor(){
	return this->color;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

bool Player::isHuman(){
	return this->isPlayerHuman;
}

vector<Piece> * Player::getPieces(){
	if(this->color == WHITE)
		return &(table->pcWhite);
	return &(table->pcBlack);
}

vector<Piece> * Player::getPieces(TableBase &t){
	if(this->color == WHITE)
		return &(t.pcWhite);
	return &(t.pcBlack);
}
