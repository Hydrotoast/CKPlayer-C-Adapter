#ifndef CKPLAYER_H
#define CKPLAYER_H

#include "Cell.h"

class CKPlayer {
public:
	Cell getMove(unsigned int deadline = 0);
	void updateBoard(Cell cell, Mark m);
};

#endif
