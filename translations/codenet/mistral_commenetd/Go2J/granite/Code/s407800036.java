
// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class s407800036{
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class to read input from the standard input
		Scanner scanner = new Scanner(System.in);

		// Declare three integer variables named A, B, and C
		int A, B, C;

		// Use the "scanner.nextInt()" method to read three integers from the standard input
		// and assign them to the variables A, B, and C respectively
		A = scanner.nextInt();
		B = scanner.nextInt();
		C = scanner.nextInt();

		// Check if the value of C is within the range of A and B
		if (C >= A && C <= B) {
			// If it is, print "Yes" to the standard output
			System.out.println("Yes");
		} else {
			// Otherwise, print "No" to the standard output
			System.out.println("No");
		}

		// Close the "Scanner" object to release system resources
		scanner.close();

		// End of code
	}
}

