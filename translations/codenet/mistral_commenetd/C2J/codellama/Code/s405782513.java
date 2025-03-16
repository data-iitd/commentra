
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] c = new int[3];
		while (sc.hasNextInt()) {
			for (int i = 0; i < 3; i++) {
				c[i] = sc.nextInt();
			}
			int sum = c[0] + c[1];
			int count = 0;
			boolean[] card = new boolean[10];
			for (int i = 0; i < 3; i++) {
				card[c[i] - 1] = true;
			}
			for (int i = 0; i < 10; i++) {
				if (!card[i] && sum + i + 1 <= 20) {
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

