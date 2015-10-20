/*
 * AITable.h
 *
 *  This class simulates a game table and is used by AI
 *  to calculate MiniMax
 *
 *  Created on: Oct 19, 2015
 *      Author: fcaldas
 */

#ifndef AITABLE_H_
#define AITABLE_H_

#include "../TableBase.h"

class AITable : public TableBase{
public:

	AITable();

	AITable(TableBase &t);

	AITable(AITable &t);

};

#endif /* AITABLE_H_ */
