
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int j = sc.nextInt();
		int a, b, c, i, k, max;

		for (i = 0; i < j; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();

			max = a;
			k = 0;
			if (max <= b) {
				max = b;
				k = 1;
			}
			if (max <= c) {
				max = c;
				k = 2;
			}

			max = max * max;
			a = a * a;
			b = b * b;
			c = c * c;
			if (k == 0 && max == b + c) {
				System.out.println("YES");
			} else if (k == 1 && max == a + c) {
				System.out.println("YES");
			} else if (k == 2 && max == a + b) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		sc.close();
	}
}

