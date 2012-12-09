#include "BoardConfig.h"

BoardConfig constructBoardConfig(int rows, int cols, int kLength, bool gravityFlag) {
	BoardConfig config;
	config.rows = rows;
	config.cols = cols;
	config.kLength = kLength;
	config.gravityFlag = gravityFlag;
	return config;
}