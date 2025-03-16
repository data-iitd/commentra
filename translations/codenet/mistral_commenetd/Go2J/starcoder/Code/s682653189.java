package main;

// This file is part of the "main" package.

import java.util.Scanner;

// The main function is the entry point of the program.
public class Main {
	// The main method is the entry point of the program.
	public static void main(String[] args) {
		// Create a new Scanner object to read from the standard input (usually the keyboard).
		Scanner input = new Scanner(System.in);

		// Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
		String s = input.next();

		// Iterate through each character in the string "s" using a for loop.
		for (int i = 0; i < s.length(); i++) {
			// Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
			System.out.print("x");
		}

		// Print a newline character to the standard output.
		System.out.println("");

		// Close the scanner object.
		input.close();
	}
}

