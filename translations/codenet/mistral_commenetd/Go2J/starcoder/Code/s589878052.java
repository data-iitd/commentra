// Package declaration
package main;

// Importing required packages
import java.util.*;

// Function definition for main function
public class Main {
	// Main function definition
	public static void main(String[] args) {
		// Creating a Scanner object
		Scanner sc = new Scanner(System.in);

		// Variable declaration and initialization
		int a, b, h, result;

		// Reading input values from the standard input
		a = sc.nextInt();
		b = sc.nextInt();
		h = sc.nextInt();

		// Calculating the result
		result = (a + b) * h / 2;

		// Printing the result to the standard output
		System.out.println(result);
	}
}

// End of the code

