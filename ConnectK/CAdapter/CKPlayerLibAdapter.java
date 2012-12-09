package ConnectK.CAdapter;

import com.sun.jna.Pointer;
import com.sun.jna.Library;

public interface CKPlayerLibAdapter extends Library {
	Pointer createAI();
	Cell getMove(Pointer aiPointer,BoardModel state);
	void updateBoard(Pointer aiPointer, Cell cell, Mark m);
}
