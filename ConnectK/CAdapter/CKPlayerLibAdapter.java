package ConnectK.CAdapter;

import com.sun.jna.Pointer;
import com.sun.jna.Library;

public interface CKPlayerLibAdapter extends Library {
	Pointer createAI(int player, int M, int N, int K, boolean G);
	void destroyAI(Pointer aiPointer);
	Cell getMove(Pointer aiPointer,BoardModel state);
	void updateBoard(Pointer aiPointer, Cell cell, Mark m);
}
