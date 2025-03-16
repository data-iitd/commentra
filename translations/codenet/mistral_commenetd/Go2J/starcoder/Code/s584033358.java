// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class
		Scanner input = new Scanner(System.in);

		// Declare two integer variables "n" and "k"
		int n, k;

		// Read the values of "n" and "k" from the standard input
		n = input.nextInt();
		k = input.nextInt();

		// Check if the value of "k" is less than or equal to the middle index of the slice "n"
		if (k <= (n+n%2)/2) {
			// If the condition is true, print "YES" to the standard output
			System.out.println("YES");
		} else {
			// If the condition is false, print "NO" to the standard output
			System.out.println("NO");
		}

		// Close the "Scanner" class
		input.close();
	}
}

// End of the code

Translate the above Java code to Python and end with comment "