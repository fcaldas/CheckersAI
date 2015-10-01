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
	int dScore = (this->color == pieceColor)?1:-1;
	
	if(p.isKing()){
		for(int i = 0; i < 4; i++){
		//generate four possible directions
			int dX, dY;
			if(i == 0){
				dX = 1; dY = 1;
			}else if(i == 1){
				dX = 1; dY = -1;
			}else if(i == 2){
				dX = -1; dY = 1;
			}else if(i == 3){
				dX = -1; dY = -1;
			}
			bool canMove = true;
			bool wasLastPieceEnemy = false;
			position move = p.getPosition();
			while(canMove){
				move.first += dX;
				move.second += dY;
				if(move.first >= 0 && move.first <= 7 &&
  				   move.second >= 0 && move.second <= 7){
					canMove = false;
					continue;
				}
				Piece *pe = table->getPieceAt(move);
				if(pe == NULL){
					if(wasLastPieceEnemy){
						//kill & move!
						AImove *pMove = new AImove(pNow, move, 1 * dScore, parent);
						moveList.push_back(pMove);
						canMove = false;
					}else{
						AImove *pMove = new AImove(pNow, move, 0, parent);
						moveList.push_back(pMove);
					}
				}else if(pe->getColor() != this->color &&
					 wasLastPieceEnemy != true){
					wasLastPieceEnemy = true;
				}else if(pe->getColor() == this->color){
					canMove = false;
				}else{
					canMove = false;
				}
			}
		
		}
	}else{
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
		}else if(table->getPieceAt(possible1)->getColor() != this->color ){
			//check next case!
			cout<<"On P1C2"<<endl;
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
		}else if(table->getPieceAt(possible2)->getColor() != this->color ){
			//check next case!
			cout<<"On P2C2"<<endl;
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
