
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str = in.next();
		String p = in.next();
		int slen = str.length();
		int plen = p.length();
		boolean flag = false;
		for (int i = 0; i < slen - plen; i++) {
			if (str.substring(i, i + plen).equals(p)) {
				flag = true;
				break;
			}
		}
		if (flag) System.out.println("Yes");
		else System.out.println("No");
	}
}

