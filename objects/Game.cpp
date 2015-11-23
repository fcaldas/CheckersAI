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
	this->player_black = new Human(BLACK, &(table));
	this->player_white = new AI(WHITE, &(table));

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
	Player *aPlayer = (this->active_player == BLACK)? player_black: player_white;

	GameMove * pMove = aPlayer->play();

	//check if player returned a movement
	if(pMove != NULL){
		//if it is valid then we execute it
		if(this->table.isMoveValid(pMove->start,
								   pMove->end,
								   aPlayer->getColor()) >= 0)
		{
			cout<<"Executing move!"<<endl;
			gameState gs = table.executeMove(pMove->start,
											 pMove->end,
											 aPlayer->getColor());
			if(gs == GAME_OK){
				//change turn
				this->active_player =  (this->active_player == BLACK) ? WHITE : BLACK;
			}else if(gs == GAME_POINT && aPlayer->isHuman() == false){
				SDL_Delay(500);
			}
		}else{
			cout<<"Invalid move to : "<<pMove->end.first <<","<<pMove->end.second <<endl;
		}
		delete pMove;
	}
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
