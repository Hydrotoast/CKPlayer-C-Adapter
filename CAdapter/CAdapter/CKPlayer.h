#ifndef CK_PLAYER_H
#define CK_PLAYER_H

#include "BoardConfig.h"
#include "BoardState.h"
#include "Mark.h"

#include <string>

#define PLAYER_A	1
#define PLAYER_B	2

class CKPlayer {
public:
	explicit CKPlayer(int player, BoardState initialState);

	virtual Cell getMove(unsigned int deadline = 0) = 0;

	void updateBoard(Cell coord, Mark m);

	std::string toString();
protected:
	int player;
	Mark playerMark;
	std::string teamName;

	BoardState board;
};

#endif