
package main;

// This file is part of the "main" package.

import java.util.Scanner;

// The main function is the entry point of the program.
public class s682653189{
	public static void main(String[] args) {
		// Initialize a variable "s" of type String.
		String s = "";

		// Create a new instance of the Scanner class to read input from the standard input (usually the keyboard).
		Scanner scanner = new Scanner(System.in);

		// Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
		s = scanner.nextLine();

		// Iterate through each character in the string "s" using a for loop.
		for (int i = 0; i < s.length(); i++) {
			// Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
			System.out.print("x");
		}

		// Print a newline character to the standard output.
		System.out.println("");

		// Indicate the end of the code.
	}
}

