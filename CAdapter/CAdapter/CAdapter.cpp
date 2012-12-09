#ifndef CADAPTER_EXPORTS_
#define CADAPTER_API __declspec(dllexport)
#define CADAPTER_EXPORTS_
#else
#define CADAPTER_API __declspec(dllimport)
#endif

#include "Cell.h"
#include "CKPlayer.h"

enum Mark {
	A, B, BLANK
};

class ConnectK : public CKPlayer {
public:
	ConnectK();
};

extern "C" {
	CADAPTER_API CKPlayer* createAI() {
		return new ConnectK();
	}

	CADAPTER_API Cell getMove(CKPlayer* player, unsigned int deadline = 0) {
		player->getMove(deadline);
	}

	CADAPTER_API void updateBoard(CKPlayer* player, Cell cell, Mark m) {
		player->updateBoard(cell, m);
	}
}