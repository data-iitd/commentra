// Package main is the entry point of the program

import (
	// Importing the 'java.util.Scanner' class for reading input from the standard input
	import java.util.Scanner;
	// Importing the 'java.lang.String' class for string manipulation functions
	import java.lang.String;
	// Importing the 'java.lang.System' class for system-specific functions
	import java.lang.System;
)

// Class Main is the entry point of the program
class Main {
	// The main method is the entry point of the program
	public static void main(String[] args) {
		// Create a new Scanner object to read input from the standard input
		Scanner scanner = new Scanner(System.in);
		// Read a string input from the standard input
		String s = scanner.next();
		// Close the scanner object
		scanner.close();

		// Use 'String.count' to count the number of occurrences of the substring "o" in the string's'
		int n = String.count(s, "o");

		// Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
		int result = 700 + n*100;
		// Use 'System.out.println' to print the result to the standard output
		System.out.println(result);
	}
}

// The code ends here

