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
	// TODO Auto-generated constructor stub
	this->loadIMG("./img/selection.png","selection");
	clickX = -1;
	clickY = -1;
}

Game::~Game() {

}

void Game::click(int x, int y){
	this->clickX = x;
	this->clickY = y;
	cout<<"clickd "<<x <<' '<<y<<flush<<endl;
}

void Game::draw(SDL_Surface *screen){
	table.draw(screen);
	cout<<clickX<<flush<<endl;

	if(clickX >= 0){
//		cout<<"isBigger!!"<<flush<<endl;
		int i = clickX / 60;
		int j = clickY / 60;
		cout<<"Plotting to "<< i*60 << ' ' << j * 60<<flush<<endl;
		this->applySurface(i*60,j*60,"selection",screen);
	}
}
