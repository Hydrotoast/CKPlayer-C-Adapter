#include "CKPlayer.h"
#include "InvalidPlayerException.h"

CKPlayer::CKPlayer(int player, BoardState board) :
	player(player), board(board)
{
	if (player == PLAYER_A)
		playerMark = Mark::A;
	else if (player == PLAYER_B)
		playerMark = Mark::B;
	else
		throw InvalidPlayerException();
}

void CKPlayer::updateBoard(Cell coord, Mark m) {
	board.occupy(coord.row, coord.col, m);
}

std::string CKPlayer::toString() {
	return teamName;
}