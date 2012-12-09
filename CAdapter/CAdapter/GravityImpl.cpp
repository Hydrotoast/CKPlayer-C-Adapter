#include "BoardConfig.h"
#include "GravityImpl.h"

using namespace std;

GravityImpl::GravityImpl(BoardState& board) :
	board(board)
{}

GravityImpl* GravityImpl::clone(BoardState& board) const {
	return new GravityImpl(board);
}

list<Cell> GravityImpl::getAvailable() {
	list<Cell> available;
	for (unsigned col = 0; col < board.config().cols; ++col) {
		for (int row = board.config().rows - 1; row >= 0; --row) {
			if (board.at(row, col) == BLANK) {
				Cell c;
				CONSTRUCT_CELL(c, row, col)
				available.push_back(c);
				break;
			}
		}
	}
	return available;
}

bool GravityImpl::occupy(size_t row, size_t col, Mark m) {
	int rowIter = board.config().rows - 1;
	do {
		Mark& cell = board.at(rowIter--, col);
		if (cell == Mark::BLANK) {
			cell = m;
			return true;
		}
	} while (rowIter >= 0);
	return false;
}