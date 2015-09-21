#include "AI.h"

AImove::AImove(position from, position to, int score, AImove * parent){
	this->score = score;
	m.start = from;
	m.end = to;
	this->previous = parent;
}


vector<AImove *> AI::possibleMovesForPiece(Piece &p, AImove *parent){
	vector<AImove *> moveList;
	pc_color pieceColor = p.getColor();
	position pNow(p.getX(),p.getY());
		
	int dPos = (pieceColor == table->getPlayerUp())?1:-1;
	int dScore = (this->pcolor == pieceColor)?1:-1;
	
	if(p.isKing()){
		//TODO: logic for king
	}else{
		//TODO: a piece can only move down until it is a king
		position possible1 = pNow;
		position possible2 = pNow;
		possible1.second += dPos;
		possible2.second += dPos;
		possible1.first -= 1;
		possible2.first += 1;
		if(table->getPieceAt(possible1) == NULL){
			if(this->checkPositionValid(possible1)){
				AImove *  pMove = new AImove(pNow, possible1, 0, parent);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible1)->getColor() != this->pcolor ){
			//check next case!
			position possible1C2 = possible1;
			possible1C2.second += dPos;
			possible1C2.first -= 1;
			if(table->getPieceAt(possible1C2) == NULL){
				if(this->checkPositionValid(possible1C2)){
					AImove *pMove = new AImove(pNow, possible1C2, 1 * dScore, parent);
					moveList.push_back(pMove);
				}
			}
		}


		if(table->getPieceAt(possible2) == NULL){
			if(this->checkPositionValid(possible2)){
				AImove * pMove = new AImove(pNow, possible2,0, parent);
				moveList.push_back(pMove);
			}
		}else if(table->getPieceAt(possible2)->getColor() != this->pcolor ){
			//check next case!
			position possible2C2 = possible2;
			possible2C2.second += dPos;
			possible2C2.first += 1;
			if(table->getPieceAt(possible2C2) == NULL){
				if(this->checkPositionValid(possible2C2)){
					AImove * pMove = new AImove(pNow, possible2C2, 1 * dScore, parent);
					moveList.push_back(pMove);
				}
			}
		}
	}
	return moveList;
}
