
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Code for A - Between Two Integers
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		// Read three integers A, B, and C from standard input
		// Check if C is between A and B (inclusive)
		if (C >= A && C <= B) {
			// If C is between A and B, print "Yes"
			System.out.println("Yes");
		} else {
			// If C is not between A and B, print "No"
			System.out.println("No");
		}
	}
}

