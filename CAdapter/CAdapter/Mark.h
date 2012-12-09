#ifndef MARK_H
#define MARK_H

enum Mark {
	BLANK, A, B
};

struct Cell {
	size_t row;
	size_t col;
};

#define CONSTRUCT_CELL(cell_, row_, col_) \
	(cell_).row = (row_); \
	(cell_).col = (col_);

#endif