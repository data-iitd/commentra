// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class
		Scanner input = new Scanner(System.in);

		// Declare three integer variables named A, B, and C
		int A, B, C;

		// Read three integers from the standard input and assign them to the variables A, B, and C respectively
		A = input.nextInt();
		B = input.nextInt();
		C = input.nextInt();

		// Check if the value of C is within the range of A and B
		if (C >= A && C <= B) {
			// If it is, print "Yes" to the standard output
			System.out.println("Yes");
		} else {
			// Otherwise, print "No" to the standard output
			System.out.println("No");
		}

		// Close the input stream
		input.close();
	}
}

