#include "BoardState.h"
#include "BoardConfig.h"
#include "GravityImpl.h"
#include "NoGravityImpl.h"

using namespace std;

BoardState::BoardState(BoardConfig config) : 
	config_(config), numOccupied_(0)
{
	board_ = new Mark[config.rows * config.cols];
	for (size_t row = 0; row < config.rows; ++row)
		for (size_t col = 0; col < config.cols; ++col)
			board_[row * config.cols + col] = Mark::BLANK;
	gravity_ = (config.gravityFlag) ? new GravityImpl(*this) : new NoGravityImpl(*this);
}

BoardState::~BoardState() {
	delete board_;
	delete gravity_;
}

BoardState::BoardState(const BoardState& board) :
	config_(board.config_), numOccupied_(board.numOccupied_)
{
	this->board_ = new Mark[config_.rows * config_.cols];
	this->gravity_ = board.gravity_->clone(*this);
	for (size_t row = 0; row < config_.rows; ++row)
		for (size_t col = 0; col < config_.cols; ++col)
			this->board_[row * config_.cols + col] = Mark::BLANK;
}

BoardState& BoardState::operator=(const BoardState& board) {
	if (&board == this)
		return *this;

	delete board_;
	delete gravity_;

	this->config_ = board.config_;
	this->numOccupied_ = board.numOccupied_;
	this->board_ = new Mark[config_.rows * config_.cols];
	this->gravity_ = board.gravity_->clone(*this);
	for (size_t row = 0; row < config_.rows; ++row)
		for (size_t col = 0; col < config_.cols; ++col)
			this->board_[row * config_.cols + col] = Mark::BLANK;
	return *this;
}

const BoardConfig& BoardState::config() const {
	return config_;
}

size_t BoardState::numOccupied() const {
	return numOccupied_;
}

bool BoardState::isOccupied(size_t row, size_t col) {
	return board_[row * config_.cols + col] == Mark::BLANK;
}

bool BoardState::inRange(size_t row, size_t col) {
	return row >= 0 && col >= 0 && 
		row < config_.rows && col < config_.cols;
}

Mark& BoardState::at(size_t row, size_t col) {
	return board_[row * config_.cols + col];
}

std::list<Cell> BoardState::getAvailable() {
	return gravity_->getAvailable();
}

bool BoardState::occupy(size_t row, size_t col, Mark m) {
	if (!inRange(row, col))
		return false;
	numOccupied_++;
	return gravity_->occupy(row, col, m);
}

//WinState BoardState::winningMove(size_t row, size_t col) {
//	int ACnt = 0;
//	int BCnt = 0;
//
//	// Horizontal wins
//	for (size_t j = 0; j + config_.kLength< config_.cols; j++) {
//		for (size_t k = j; k < config_.cols + config_.kLength; k++) {
//			switch (board_[row * config_.cols + k]) {
//				case Mark::A:
//					ACnt++;
//					break;
//				case Mark::B:
//					BCnt++;
//					break;
//				default:
//					break;
//			}
//		}
//		if (ACnt == config_.kLength)
//			return WinState::A_WIN;
//		else if (BCnt == config_.kLength)
//			return WinState::B_WIN;
//	}
//
//	return WinState::NO_WINNER;
//}

WinState BoardState::isEnd() {
	int ACnt = 0;
	int BCnt = 0;

	/* Check all the horizontal groups of config_.kLength */
	for (size_t row = 0; row < config_.rows; row++ )
	{
		for (size_t col = 0; col < config_.cols - config_.kLength + 1; col++, ACnt = 0, BCnt = 0 )
		{
			for (size_t j = col; j < config_.cols + col && j < config_.cols; j++ )
			{
                switch (board_[row * config_.cols + j])
			    {
				case Mark::A:
					ACnt++;
					break;
				case Mark::B:
					BCnt++;
					break;
				default:
					break;
			    }
            }

			if (ACnt == config_.kLength)
				return WinState::A_WIN;
			else if (BCnt == config_.kLength)
				return WinState::B_WIN;
		}
	}

	/* Check all the vertical groups of config_.kLength */
	for (size_t col = 0; col < config_.cols; col++ )
	{
		for (size_t row = 0; row < config_.rows - config_.kLength + 1; row++, ACnt = 0, BCnt = 0 )
		{
			for (size_t i = row; i < config_.kLength + row && i < config_.rows; i++ )
			{
			    switch (board_[i * config_.cols + col])
			    {
				case Mark::A:
					ACnt++;
					break;
				case Mark::B:
					BCnt++;
					break;
				default:
					break;
			    }
			}						

            if (ACnt == config_.kLength)
                return WinState::A_WIN;
            else if (BCnt == config_.kLength)
                return WinState::B_WIN;
		}
	}

	/* Check each diagonal forward group of config_.kLength */
	/*
		  X
		 X
	    X
	*/
	for (size_t col = 0; col < config_.cols-config_.kLength + 1; col++ )
	{
		for (size_t row = config_.kLength - 1; row < config_.rows; row++, ACnt = 0, BCnt = 0 ) 
		{
			for (size_t i = row, j = col; j < config_.kLength + col && i >= 0 && j < config_.cols; i--, j++ )
			{
				switch (board_[i * config_.cols + j])
				{
				case Mark::A:
					ACnt++;
					break;
				case Mark::B:
					BCnt++;
					break;
				default:
					break;
				}
			}

			if (ACnt == config_.kLength)
                return WinState::A_WIN;
            else if (BCnt == config_.kLength)
                return WinState::B_WIN;
		}
	}
	
	/* Check each diagonal backward group of config_.kLength */
	/*
	    X
		 X
		  X
	*/
	for (size_t col = 0; col < config_.cols - config_.kLength + 1; col++ )
	{
		for (size_t row = 0; row < config_.rows - config_.kLength + 1; row++, ACnt = 0, BCnt = 0 ) 
		{
			for (size_t i = row, j = col; i < config_.kLength + row && i < config_.rows && j < config_.cols; i++, j++ )
			{
				switch (board_[i * config_.cols & j])
				{
				case Mark::A:
					ACnt++;
					break;
				case Mark::B:
					BCnt++;
					break;
				default:
					break;
				}
			}

			if ( ACnt == config_.kLength )
                return WinState::A_WIN;
            else if ( BCnt == config_.kLength )
                return WinState::B_WIN;
		}
	}

	return WinState::NO_WINNER;
}

bool BoardState::isTie() {
	return numOccupied_ == config_.rows * config_.cols; 
}

bool BoardState::isWin() {
	switch (isEnd())
	{
		case A_WIN:
		    return true;
	    case B_WIN: 
		    return true;
        default:
		    return false;
	}
}