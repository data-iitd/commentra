// Package declaration
package main;

// Importing required packages
import java.util.Scanner;

// Function definition for main function
public class Main {
	// Main function
	public static void main(String[] args) {
		// Variable declaration and initialization
		int a, b, h;

		// Reading input values from the standard input
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		h = scanner.nextInt();

		// Calculating the result
		int result = (a + b) * h / 2;

		// Printing the result to the standard output
		System.out.println(result);
	}
}

// End of the code
