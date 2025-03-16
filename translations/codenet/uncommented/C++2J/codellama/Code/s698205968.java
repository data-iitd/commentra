import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m, f, r;
		while (sc.hasNextInt()) {
			m = sc.nextInt();
			f = sc.nextInt();
			r = sc.nextInt();
			if (m == -1 || f == -1) System.out.print("F");
			else if (m + f >= 80) System.out.print("A");
			else if (m + f >= 65) System.out.print("B");
			else if (m + f >= 50 || r >= 50) System.out.print("C");
			else if (m + f >= 30) System.out.print("D");
			else System.out.print("F");
			System.out.println();
		}
		sc.close();
	}
}

