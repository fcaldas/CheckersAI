/*
 * TableBase.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fcaldas
 */

#include "TableBase.h"

TableBase::TableBase(pc_color colorup){
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
}


TableBase::TableBase() {
	// TODO Auto-generated constructor stub

}

TableBase::~TableBase() {
	// TODO Auto-generated destructor stub
}

pc_color TableBase::getPlayerUp(){
	return this->color_up;
}

Piece* TableBase::getPieceAt(position p){
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

Piece* TableBase::getPiece(position p, pc_color color){
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


void TableBase::checkPiecePromotion(Piece *p, position &to, pc_color pcolor){
	if(this->color_up == pcolor && to.second == 7){
		p->king = true;
	}else if(this->color_up != pcolor && to.second == 0){
		p->king = true;
	}
}


gameState TableBase::executeMove(position &from, position &to, pc_color pcolor){
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
int TableBase::isMoveValid(position &initial, position &final, pc_color pcolor){
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
		if(abs(final.second - initial.second) == abs(final.first - initial.first) &&
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
void TableBase::removeKilled(position &initial, position &final, pc_color pcolor){
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

bool TableBase::removePiece(Piece *toRemove){
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
