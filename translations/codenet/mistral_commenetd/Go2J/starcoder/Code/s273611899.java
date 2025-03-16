// Package main is the entry point of the program

import (
	// Importing the 'Scanner' class for input/output operations
	import java.util.Scanner;
)

// Function main is the entry point of the program
public class Main {

	// Standard code to read input from stdin
	public static void main(String[] args) {
		// Creating a 'Scanner' object to read input from stdin
		Scanner input = new Scanner(System.in);

		// Loop infinitely until user inputs 0 for both 'n' and 'x'
		for (true) {
			// Read user input for 'n' and 'x'
			int n = input.nextInt();
			int x = input.nextInt();

			// Check if user has entered 0 for both 'n' and 'x' to break the loop
			if (n == 0 && x == 0) {
				break;
			}

			// Declaring an integer variable 'c' to store the count of triples
			int c = 0;

			// Inner loop to find triples that sum up to 'x'
			for (int i = 1; i <= n-2; i++) {
				// Inner loop to compare 'j' with all the remaining numbers
				for (int j = i + 1; j <= n-1; j++) {
					// Inner loop to compare 'k' with all the remaining numbers
					for (int k = j + 1; k <= n; k++) {
						// Check if the sum of 'i', 'j', and 'k' equals 'x'
						if (i+j+k == x) {
							// Increment the count 'c' if the condition is true
							c++;
						}
					}
				}
			}

			// Print the count of triples that sum up to 'x'
			System.out.println(c);
		}

		// Standard code to close input from stdin
		input.close();
	}

// End of the code
}

