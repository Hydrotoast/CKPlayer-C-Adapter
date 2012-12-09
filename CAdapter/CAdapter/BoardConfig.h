#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

struct BoardConfig {
	unsigned int rows;
	unsigned int cols;
	unsigned int kLength;
	bool gravityFlag;
};

BoardConfig constructBoardConfig(int rows, int cols, int kLength, bool gravityFlag);

#endif