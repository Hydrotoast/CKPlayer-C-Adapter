#include "BoardConfig.h"
#include "NoGravityImpl.h"

using namespace std;

NoGravityImpl::NoGravityImpl(BoardState& board) :
	GravityImpl(board)
{}

NoGravityImpl* NoGravityImpl::clone(BoardState& board) const {
	return new NoGravityImpl(board);
}

list<Cell> NoGravityImpl::getAvailable() {
	list<Cell> available;
	for (size_t row = 0; row < board.config().rows; ++row)
		for (size_t col = 0; col < board.config().cols; ++col)
			if (board.at(row, col) == BLANK) {
				Cell c;
				CONSTRUCT_CELL(c, row, col)
				available.push_back(c);
			}
	return available;
}

bool NoGravityImpl::occupy(size_t row, size_t col, Mark m) {
	Mark& cell = board.at(row, col);
	if (cell != Mark::BLANK)
		return false;
	cell = m;
	return true;
}