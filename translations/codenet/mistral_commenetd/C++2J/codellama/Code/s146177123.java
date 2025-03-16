
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, t;
		boolean[] st = new boolean[7];
		while (sc.hasNextInt()) {
			n = sc.nextInt();
			if (n == 0)
				break;
			for (int i = 0; i < 7; i++)
				st[i] = false;
			for (int i = 0; i < n; i++) {
				t = sc.nextInt();
				char[] ans = new char[8];
				for (int j = 0; j < 7; j++) {
					ans[j] = st[j] ^ seg[t][j] ? '1' : '0';
					st[j] = seg[t][j];
				}
				System.out.println(ans);
			}
		}
	}

	static boolean[][] seg = { { false, true, true, true, true, true, true },
			{ false, false, false, false, true, true, false },
			{ true, false, true, true, false, true, true },
			{ true, false, false, true, true, true, true },
			{ true, true, false, false, true, true, false },
			{ true, true, false, true, true, false, true },
			{ true, true, true, true, true, false, true },
			{ false, true, false, false, true, true, true },
			{ true, true, true, true, true, true, true },
			{ true, true, false, true, true, true, true } };
}

