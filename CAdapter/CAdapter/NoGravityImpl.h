#ifndef NO_GRAVITY_IMPL_H
#define NO_GRAVITY_IMPL_H

#include "GravityImpl.h"

class NoGravityImpl : public GravityImpl {
public:
	explicit NoGravityImpl(BoardState& board);

	virtual NoGravityImpl* clone(BoardState& board) const;

	virtual std::list<Cell> getAvailable();
	virtual bool occupy(size_t row, size_t col, Mark m);
};

#endif