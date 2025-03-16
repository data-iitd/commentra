import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			int m = sc.nextInt();
			int f = sc.nextInt();
			int r = sc.nextInt();

			if (m == -1 || f == -1) {
				System.out.println("F");
				continue;
			}

			if (m + f >= 80) {
				System.out.println("A");
				continue;
			}

			if (m + f >= 65) {
				System.out.println("B");
				continue;
			}

			if (m + f >= 50 || r >= 50) {
				System.out.println("C");
				continue;
			}

			if (m + f >= 30) {
				System.out.println("D");
				continue;
			}

			System.out.println("F");
			System.out.println();
		}
	}
}

