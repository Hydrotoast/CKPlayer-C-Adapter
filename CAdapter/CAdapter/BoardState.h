#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include "BoardConfig.h"
#include "Mark.h"

#include <list>

class GravityImpl;

enum WinState {
	A_WIN, B_WIN, DRAW, NO_WINNER
};

class BoardState {
public:
	explicit BoardState(BoardConfig config);
	~BoardState();
	BoardState(const BoardState& board);
	BoardState& operator=(const BoardState& board);
	BoardState clone();

	const BoardConfig& config() const;
	size_t numOccupied() const;

	bool isOccupied(size_t row, size_t col);
	bool inRange(size_t row, size_t col);
	
	Mark& at(size_t row, size_t col);

	std::list<Cell> getAvailable();
	bool occupy(size_t row, size_t col, Mark m);
	WinState winningMove(size_t row, size_t col, Mark m);

	WinState isEnd();
	bool isTie();
	bool isWin();
protected:
	BoardConfig config_;
	size_t numOccupied_;

	Mark* board_;

	GravityImpl* gravity_;
};

#endif