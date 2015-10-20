/*
 * AITable.cpp
 *
 *  Created on: Oct 19, 2015
 *      Author: fcaldas
 */

#include "AITable.h"

AITable::AITable(TableBase &t): TableBase(WHITE) {
	this->pcBlack = t.pcBlack;
	this->pcWhite = t.pcWhite;
	this->color_up = t.color_up;
}

AITable::AITable(){

}

AITable::AITable(AITable &t){
	this->pcBlack = t.pcBlack;
	this->pcWhite = t.pcWhite;
	this->color_up = t.color_up;
}
