
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		String S = in.next();

		boolean found = false;

		for (int offset = 0; offset < patternBase.length(); offset++) {
			String top = patternBase.substring(0, offset);
			String bottom = patternBase.substring(offset);

			int topSearch = S.indexOf(top);
			if (topSearch!= -1) {
				int bottomSearch = S.lastIndexOf(bottom);
				if (bottomSearch!= -1) {
					int sepCount = 0;

					if (topSearch!= 0) {
						sepCount++;
					}
					if (bottomSearch!= S.length() - bottom.length()) {
						sepCount++;
					}
					if (bottomSearch + bottom.length()!= S.length()) {
						sepCount++;
					}

					if (sepCount <= 1) {
						found = true;
						break;
					}
				}
			}
		}

		System.out.println(found? "YES" : "NO");
	}
}

