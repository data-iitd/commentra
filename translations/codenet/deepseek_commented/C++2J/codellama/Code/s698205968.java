import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m, f, r;
		while (sc.hasNextInt()) { // 1. The program reads three integers: m, f, and r from the standard input.
			m = sc.nextInt();
			f = sc.nextInt();
			r = sc.nextInt();
			if (m == -1 || f == -1) System.out.print("F"); // 2. It then checks if any of these integers are -1, in which case it outputs "F".
			else if (m + f >= 80) System.out.print("A"); // 3. If not, it checks if the sum of m and f is 80 or more, in which case it outputs "A".
			else if (m + f >= 65) System.out.print("B"); // 4. If not, it checks if the sum of m and f is 65 or more, in which case it outputs "B".
			else if (m + f >= 50 || r >= 50) System.out.print("C"); // 5. If not, it checks if the sum of m and f is 50 or more, or if r is 50 or more, in which case it outputs "C".
			else if (m + f >= 30) System.out.print("D"); // 6. If not, it checks if the sum of m and f is 30 or more, in which case it outputs "D".
			else System.out.print("F"); // 7. If none of the above conditions are met, it outputs "F".
			System.out.println(); // 8. The program continues to read and process new sets of m, f, and r values until all three are -1.
		}
	}
}

