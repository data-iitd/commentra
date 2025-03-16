import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int[] c = new int[3];
			for (int i = 0; i < 3; i++) {
				c[i] = in.nextInt();
			}
			int count = 0;
			int sum = c[0] + c[1];
			for (int i = 0; i < 10; i++) {
				if (sum + i + 1 <= 20 && c[0]!= i + 1 && c[1]!= i + 1 && c[2]!= i + 1) {
					count++;
				}
			}
			if (count >= 4) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}
}

