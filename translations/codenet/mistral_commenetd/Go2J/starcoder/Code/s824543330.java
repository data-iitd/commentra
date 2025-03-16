// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);

		// Declare and initialize two integer variables, a and b, using input.nextInt()
		int a = input.nextInt();
		int b = input.nextInt();

		// Check if the product of a and b is even using the modulo operator (%).
		// If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
		if (a*b%2 == 0) {
			// If the condition is true, print the message "Even"
			System.out.println("Even");
		} else {
			// If the condition is false, print the message "Odd"
			System.out.println("Odd");
		}
	}
}

// End of code

