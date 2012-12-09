package ConnectK.CAdapter;
import java.util.Arrays;
import java.util.List;
import com.sun.jna.Structure;

public class Cell extends Structure {
	public int row;
	public int col;
	
	@Override
	protected List<String> getFieldOrder() {
		return Arrays.asList(new String[] {
			"row", "col"
		});
	}
}
