/*
 * Player.cpp
 *
 *  Created on: 26 juil. 2015
 *      Author: filipe
 */

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(bool isWhite, Table table) {
	this->table = table;
	this->isWhite = isWhite;

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
	//TODO: implement
	return false;
}

