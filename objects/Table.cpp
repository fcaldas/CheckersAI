/*
 * Table.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Table.h"
#include <iostream>
#include <cmath>

using namespace std;

Table::Table():Table(WHITE){

}


Table::Table(pc_color colorup) {
	//populate the table
	int row = 0;
	this->color_up = colorup;
	for(int i = 0; i < 12; i++){
		row = i/4;
		int offset = ( row%2 == 1)?0:1;
		if(colorup == WHITE)
			pcWhite.push_back(Piece(offset+(i-row*4)*2, row, WHITE));
		else
			pcBlack.push_back(Piece(offset+(i-row*4)*2, row, BLACK));
	}

	for(int i = 0; i < 12; i++){
		row = i/4;
		int offset = ( row%2 == 1)?1:0;
		if(colorup == WHITE)
			pcBlack.push_back(Piece((i - row * 4)*2 + offset, 5 + row, BLACK));
		else
			pcWhite.push_back(Piece((i - row * 4)*2 + offset, 5 + row, WHITE));
	}

	this->loadIMG("./img/brownblock.bmp", "bblock");
	this->loadIMG("./img/whiteblock.bmp", "wblock");
	this->loadIMG("./img/bpiece.png", "bpiece");
	this->loadIMG("./img/wpiece.png","wpiece");
	this->loadIMG("./img/crown.png", "crown");
}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

pc_color Table::getPlayerUp(){
	return this->color_up;
}

Piece* Table::getPieceAt(position p){
	for(int i = 0; i < this->pcWhite.size(); i++){
		if(pcWhite[i].isAtPosition(p))
			return &(pcWhite[i]);
	}
	for(int i = 0; i < this->pcBlack.size(); i++){
		if(pcBlack[i].isAtPosition(p))
			return &(pcBlack[i]);
	}
	return NULL;
}

Piece* Table::getPiece(position p, pc_color color){
	if(color == WHITE){
		for(int i = 0; i < this->pcWhite.size(); i++){
			if(pcWhite[i].isAtPosition(p))
				return &(pcWhite[i]);
		}
	}else if(color == BLACK){
		for(int i = 0; i < this->pcBlack.size(); i++){
			if(pcBlack[i].isAtPosition(p))
				return &(pcBlack[i]);
		}
	}
	return NULL;
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
		if(pcBlack[i].isKing()){
			this->applySurface(pcBlack[i].getX() * 60, pcBlack[i].getY() * 60,"crown",screen);					
		}
	}

	for(int i = 0; i < this->pcWhite.size(); i++){
		this->applySurface(pcWhite[i].getX() * 60, pcWhite[i].getY() * 60,"wpiece",screen);
		if(pcWhite[i].isKing()){
			this->applySurface(pcWhite[i].getX() * 60, pcWhite[i].getY() * 60,"crown",screen);	
		}
	}

}

void Table::checkPiecePromotion(Piece *p, position &to, pc_color pcolor){
	if(this->color_up == pcolor && to.second == 7){
		p->king = true;
	}else if(this->color_up != pcolor && to.second == 0){
		p->king = true;
	}
}


gameState Table::executeMove(position &from, position &to, pc_color pcolor){
	int points = this->isMoveValid(from, to, pcolor);
	if(points >= 0){
		Piece * p = this->getPiece(from,pcolor);
		checkPiecePromotion(p, to, pcolor);
		if(points > 0){
			removeKilled(from,to,pcolor);
			p->setPosition(to);
			return GAME_POINT;
		}else{
			p->setPosition(to);
			return GAME_OK;
		}
	}else{
		return GAME_INVALIDMOVE;
	}
}

/* Check if a movement is valid, sends two positions
 * returns int.
 *
 * ret:
 * 			0: ok
 * 		   -1: invalid
 *		   >0: there are pieces to be removed
 */
int Table::isMoveValid(position &initial, position &final, pc_color pcolor){
	Piece *toMove = this->getPiece(initial,pcolor);
	bool isKing = toMove->isKing();
	pc_color otherColor = (pcolor == WHITE)?BLACK:WHITE;
	if(toMove == NULL)
		return -1;
	bool isLeftMove = (initial.first > final.first)?true:false;
  	bool hasPieceBetween = false;

	if(!isKing){
		//playing from top
		if(this->getPlayerUp() == pcolor){
			if(isLeftMove){
				position pLook = initial;
				pLook.first -= 1;
				pLook.second += 1;
				Piece *enemy = this->getPiece(pLook, otherColor);
				if(enemy == NULL &&
				   final.second == pLook.second &&
				   final.first == pLook.first)
					return 0;
				else if(enemy != NULL &&
						final.second == pLook.second + 1 &&
						final.first == pLook.first - 1)
					return 1;
			}else{
				position pLook = initial;
				pLook.first += 1;
				pLook.second += 1;
				Piece *enemy = this->getPiece(pLook, otherColor);
				if(enemy == NULL &&
				   final.second == pLook.second &&
				   final.first == pLook.first)
					return 0;
				else if(enemy != NULL &&
						final.second == pLook.second + 1 &&
						final.first == pLook.first + 1)
					return 1;
			}
		}else{
		//playing from bottom
			if(isLeftMove){
				position pLook = initial;
				pLook.first -= 1;
				pLook.second -= 1;
				Piece *enemy = this->getPiece(pLook, otherColor);
				if(enemy == NULL &&
					final.second == pLook.second &&
					final.first == pLook.first)
					return 0;
				else if(enemy != NULL &&
					final.second == pLook.second - 1 &&
					final.first == pLook.first - 1)
					return 1;
			}else{
				position pLook = initial;
				pLook.first += 1;
				pLook.second -= 1;
				Piece *enemy = this->getPiece(pLook, otherColor);
				if(enemy == NULL &&
					final.second == pLook.second &&
					final.first == pLook.first)
					return 0;
				else if(enemy != NULL &&
					final.second == pLook.second - 1 &&
					final.first == pLook.first + 1)
					return 1;
				}
			}
	}else{
		//check if move is diagonal and ends inside the table
		if(final.second - initial.second == final.first - initial.second &&
		   final.first >= 0 && final.first <= 7 &&
		   final.second >= 0 && final.second <= 7 &&
		   final.first != initial.first){
			//now check for other pieces on the path
			//and on target case
			if(this->getPieceAt(final) != NULL){
			    return -1;
			}
			int dX;
			int dY;
			dX = (final.first - initial.first)/abs(final.first - initial.first);
			dY = (final.second- initial.second)/abs(final.second - initial.second);
			int i = initial.first + dX;
			int j = initial.second + dY;
			//search for pieces on the line!
			for(i,j; i != final.first && j != final.second; i += dX, j += dY){
				position pTemp;
				pTemp.first = i;
				pTemp.second = j;
				Piece * p = this->getPieceAt(pTemp);
				if(p != NULL){
					if(p->getColor() == pcolor){
						return -1;
					}else if(i == final.first - dX &&
						 j == final.second -dY){
						return 1;					
					}else{
						return -1;
					}

				}
			}
			return 0;
		
		}
	
	}
	return -1;
}

/* Remove a killed piece from the table
 *
 */
void Table::removeKilled(position &initial, position &final, pc_color pcolor){
	Piece *toMove = this->getPiece(initial,pcolor);
	bool isKing = toMove->isKing();
	pc_color otherColor = (pcolor == WHITE)?BLACK:WHITE;
	bool isLeftMove = (initial.first > final.first)?true:false;
  	bool hasPieceBetween = false;
	int dX = (final.first - initial.first)/abs(final.first - initial.first);
	int dY = (final.second - initial.second)/abs(final.second - initial.second);
	position toLook = final;
	toLook.first -= dX;
	toLook.second -= dY;
	Piece *toKill = this->getPieceAt(toLook);
	if(toKill != NULL && toKill->getColor() != pcolor){
		removePiece(toKill);
	}
}

bool Table::removePiece(Piece *toRemove){
	for(int i = 0; i < pcBlack.size(); i++){
		if(&(pcBlack[i]) == toRemove){
			pcBlack.erase(pcBlack.begin() + i);
			return true;
		}
	}
	for(int i = 0; i < pcWhite.size(); i++){
		if(&(pcWhite[i]) == toRemove){
			pcWhite.erase(pcWhite.begin() + i);
			return true;
		}
	}
	return false;
}
