import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize three integer variables 'a', 'b', and 'c'
		int a, b, c;

		// Read values of 'a', 'b', and 'c' from the standard input
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();

		// Check if the given condition is true
		if ((100*a + 10*b + c) % 4 == 0) {
			// If the condition is true, print 'YES' to the standard output
			System.out.println("YES");
		}
		else {
			// If the condition is false, print 'NO' to the standard output
			System.out.println("NO");
		}
	}
}

