#include "AI.h"
#include "AITable.h"


/*
 * Create a GameMove for AI
 */
AImove::AImove(position from, position to, int score, AImove * parent, AITable tnew){
	this->score = score;
	m.start = from;
	m.end = to;
	this->previous = parent;
	this->tableGame = tnew;
}

vector<AImove *> AI::possibleMovesForPiece(Piece &p, AImove *parent){
	vector<AImove *> moveList;
	TableBase * table;

	//go to parent level to get table
	if(parent == NULL)
		table = this->table;
	else
		table = &(parent->tableGame);

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
				if(move.first < 0 || move.first > 7 ||
  				   move.second < 0 || move.second > 7){
					canMove = false;
					continue;
				}
				Piece *pe = table->getPieceAt(move);
				if(pe == NULL){
					if(wasLastPieceEnemy){
						//kill & move!
						AITable newTable(*(table));
						newTable.executeMove(pNow, move, p.getColor());
						AImove *pMove = new AImove(pNow, move, 1 * dScore, parent, newTable);
						moveList.push_back(pMove);
						canMove = false;
					}else{
						AITable newTable(*(table));
						newTable.executeMove(pNow, move, p.getColor());
						AImove *pMove = new AImove(pNow, move, 0, parent, newTable);
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
				if(possible1.second == 7 || possible1.second == 0){
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible1, p.getColor());
					AImove *  pMove = new AImove(pNow, possible1, POINT_PROMOTE * dScore, parent, newTable);
					moveList.push_back(pMove);
				}else{
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible1, p.getColor());
					AImove *  pMove = new AImove(pNow, possible1, 0, parent, newTable);
					moveList.push_back(pMove);
				}
			}
		//there is an enemy there
		}else if(table->getPieceAt(possible1)->getColor() != this->color ){
			//check next case!
			position possible1C2 = possible1;
			possible1C2.second += dPos;
			possible1C2.first -= 1;
			if(table->getPieceAt(possible1C2) == NULL){
				if(this->checkPositionValid(possible1C2)){
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible1C2, p.getColor());
					AImove *pMove = new AImove(pNow, possible1C2, 1 * dScore, parent, newTable);
					moveList.push_back(pMove);
				}
			}
		}

		if(table->getPieceAt(possible2) == NULL){
			if(this->checkPositionValid(possible2)){
				if(possible2.second == 7 || possible2.second == 0){
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible2, p.getColor());
					AImove *  pMove = new AImove(pNow, possible2, POINT_PROMOTE * dScore, parent, newTable);
					moveList.push_back(pMove);
				}else{
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible2, p.getColor());
					AImove * pMove = new AImove(pNow, possible2,0, parent, newTable);
					moveList.push_back(pMove);
				}
			}
		}else if(table->getPieceAt(possible2)->getColor() != this->color ){
			//check next case!
			position possible2C2 = possible2;
			possible2C2.second += dPos;
			possible2C2.first += 1;
			if(table->getPieceAt(possible2C2) == NULL){
				if(this->checkPositionValid(possible2C2)){
					AITable newTable(*(table));
					newTable.executeMove(pNow, possible2C2, p.getColor());
					AImove * pMove = new AImove(pNow, possible2C2, 1 * dScore, parent, newTable);
					moveList.push_back(pMove);
				}
			}
		}
	}
	return moveList;
}
