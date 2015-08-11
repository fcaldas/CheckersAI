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
