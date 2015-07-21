/*
 * Table.cpp
 *
 *  Created on: 21 juil. 2015
 *      Author: filipe
 */

#include "Table.h"

Table::Table() {
	//populate the table
	int row = 0;
	for(int i = 0; i < 12; i++){
		row = i%4;
		int offset = (row == 1)?1:0;
		pcBlack.push_back(Piece(i - row * 4 + offset, row));
	}

	for(int i = 0; i < 12; i++){
		row = i%4;
		int offset = (row == 1)?0:1;
		pcWhite.push_back(Piece(i - row * 4 + offset, 5 + row));
	}
}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

