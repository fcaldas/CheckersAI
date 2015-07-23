/*
 * Table.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Table.h"
#include <iostream>

using namespace std;

Table::Table() {
	//populate the table
	int row = 0;

	for(int i = 0; i < 12; i++){
		row = i%4;
		int offset = ( row%2 == 1)?0:1;
		pcBlack.push_back(Piece(offset + (i-row*4)*2, row, true));
	}

	for(int i = 0; i < 12; i++){
		row = i%4;
		int offset = (row == 1)?0:1;
		pcWhite.push_back(Piece(i - row * 4 + offset, 5 + row, false));
	}

	this->loadIMG("./img/brownblock.bmp", "bblock");
	this->loadIMG("./img/whiteblock.bmp", "wblock");
	this->loadIMG("./img/bpiece.png", "bpiece");
	this->loadIMG("./img/wpiece.png","wpiece");
}

Table::~Table() {
	// TODO Auto-generated destructor stub
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
