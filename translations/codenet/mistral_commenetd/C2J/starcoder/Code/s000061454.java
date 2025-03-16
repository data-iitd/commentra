
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int n = sc.nextInt();

			if (a == -1 && b == -1 && n == -1) {
				break;
			}

			a -= a / b * b;

			int sum = 0;

			for (int i = 1; i <= n; i++) {
				a *= 10;

				for (int j = 9; j >= 0; j--) {
					if (b * j <= a) {
						a -= b * j;
						sum += j;
						break;
					}
				}
			}

			System.out.println(sum);
		}
	}
}

