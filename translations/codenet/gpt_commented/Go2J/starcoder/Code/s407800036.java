import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables A, B, and C to hold integer values
		int A, B, C;
		
		// Read three integers from standard input
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		
		// Check if C is within the range defined by A and B (inclusive)
		if (C >= A && C <= B) {
			// If C is within the range, print "Yes"
			System.out.println("Yes");
		} else {
			// If C is outside the range, print "No"
			System.out.println("No");
		}
	}
}
