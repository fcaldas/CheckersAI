/*
 * Game.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {

	clickX = -1;
	clickY = -1;
	this->player_black = new Human(BLACK, &(this->table));
	this->player_white = new AI(WHITE, &(this->table));

	this->active_player = BLACK;
}

Game::~Game() {

}

void Game::click(int x, int y){
	int i = x / 60;
	int j = y / 60;
	if( i >= 0 && i <= 7 && j >= 0 && j <= 7){
		if(active_player == WHITE)
			this->player_white->click(i,j);
		else
			this->player_black->click(i,j);
	}

}

void Game::play(){

}

void Game::mouseMove(int x, int y){
	int i = x / 60;
	int j = y / 60;
	if( i >= 0 && i <= 7 && j >= 0 && j <= 7){
		if(active_player == WHITE)
			this->player_white->mouseMove(i,j);
		else
			this->player_black->mouseMove(i,j);
	}
}

void Game::draw(SDL_Surface *screen){
	table.draw(screen);
	player_black->draw(screen);
	player_white->draw(screen);
}
