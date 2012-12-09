#ifndef GRAVITY_IMPL_H
#define GRAVITY_IMPL_H

#include "BoardState.h"
#include "Mark.h"

#include <list>

class GravityImpl {
public:
	explicit GravityImpl(BoardState& board);

	virtual GravityImpl* clone(BoardState& board) const;

	virtual std::list<Cell> getAvailable();
	virtual bool occupy(size_t row, size_t col, Mark m);
protected:
	BoardState& board;
};

#endif