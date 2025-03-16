
// Package declaration
package main;

// Importing the required package
import java.util.Scanner;

// Class declaration
public class s400924672{
	// s400924672 method definition
	public static void main(String[] args) {
		// Creating a new instance of the Scanner class
		Scanner scanner = new Scanner(System.in);

		// Declaring variables r, D, and x of type int
		int r, D, x;

		// Reading input values for r, D, and x from the standard input
		r = scanner.nextInt();
		D = scanner.nextInt();
		x = scanner.nextInt();

		// Comment for the for loop
		// Loop runs 10 times
		for (int i = 1; i <= 10; i++) {
			// Print the result of the current iteration
			System.out.println(r * x - D);

			// Update the value of x for the next iteration
			x = r * x - D;
		}

		// Close the scanner
		scanner.close();
	}
}

// End of the code