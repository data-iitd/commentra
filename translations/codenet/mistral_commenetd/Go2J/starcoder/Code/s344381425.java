// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);

		// Declare and initialize three integer variables "a", "b", and "c"
		// with values read from the standard input using the "next" method
		int a = input.nextInt();
		int b = input.nextInt();
		int c = input.nextInt();

		// Check if the condition "a < b && b < c" is true using an if statement
		if (a < b && b < c) {
			// If the condition is true, print the string "Yes" to the standard output
			System.out.println("Yes");
		} else {
			// If the condition is false, print the string "No" to the standard output
			System.out.println("No");
		}

		// Close the Scanner object
		input.close();

		// Return from the main method
		return;
	}
}

// End of code

