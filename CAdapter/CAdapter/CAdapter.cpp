#ifndef CADAPTER_EXPORTS_
#define CADAPTER_API __declspec(dllexport)
#define CADAPTER_EXPORTS_
#else
#define CADAPTER_API __declspec(dllimport)
#endif

#include "CKPlayer.h"

class ConnectK : public CKPlayer {
public:
	ConnectK(int player, int M, int N, int K, bool G) :
		CKPlayer(player, BoardState(constructBoardConfig(M, N, K, G)))
	{}

	Cell getMove(unsigned int deadline = 0) {
		return board.getAvailable().front();
	}
};

extern "C" {
	CADAPTER_API CKPlayer* createAI(int player, int M, int N, int K, bool G) {
		return new ConnectK(player, M, N, K, G);
	}

	CADAPTER_API void destroyAI(CKPlayer* player) {
		delete player;
	}

	CADAPTER_API Cell getMove(CKPlayer* player, unsigned int deadline = 0) {
		return player->getMove(deadline);
	}

	CADAPTER_API void updateBoard(CKPlayer* player, Cell cell, Mark m) {
		player->updateBoard(cell, m);
	}
}