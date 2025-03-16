
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new scanner for reading input from stdin
		Scanner sc = new Scanner(System.in);

		// Read the first three integers from the input
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		// Check if the condition is true
		if (a+b >= c) {
			// If true, print "Yes" to the output
			System.out.println("Yes");
		} else {
			// If false, print "No" to the output
			System.out.println("No");
		}

		// End of code

	}

}

Translate the above Java code to C++ and end with comment "