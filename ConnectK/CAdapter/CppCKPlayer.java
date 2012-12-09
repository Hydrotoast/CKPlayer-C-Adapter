package ConnectK.CAdapter;
import java.awt.Point;


import com.sun.jna.Pointer;
import com.sun.jna.Native;

public class CppCKPlayer extends CKPlayer {
	private CKPlayerLibAdapter AILibrary;
	private Pointer aiPointer;
	
	public CppCKPlayer(String lib, byte player, BoardModel state) {
		super(player, state);
		AILibrary = (CKPlayerLibAdapter) 
			Native.loadLibrary(lib, CKPlayerLibAdapter.class);
		aiPointer = AILibrary.createAI();
	}
	
	public void updateBoard(Cell cell, Mark m) {
		AILibrary.updateBoard(aiPointer, cell, m);
	}

	@Override
	public Point getMove(BoardModel state) {
		Cell c = AILibrary.getMove(aiPointer, state);
		return new Point(c.row, c.col);
	}

	@Override
	public Point getMove(BoardModel state, int deadline) {
		Cell c = AILibrary.getMove(aiPointer, state);
		return new Point(c.row, c.col);
	}
}
