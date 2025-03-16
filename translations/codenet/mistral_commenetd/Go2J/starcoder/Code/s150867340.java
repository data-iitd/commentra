// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a new "Scanner" object
		Scanner input = new Scanner(System.in);

		// Declare and initialize two integer variables "a" and "b"
		// by reading input values from the standard input using the "next" method
		int a = input.nextInt();
		int b = input.nextInt();

		// Calculate the product of "a" and "b" and store it in a new variable "product"
		int product = a * b;

		// Check if the product is even or odd using an if statement
		if (product % 2 == 0) {
			// If the product is even, print the message "Even" to the standard output
			System.out.println("Even");
		} else {
			// If the product is odd, print the message "Odd" to the standard output
			System.out.println("Odd");
		}
	}
}

// End of code

