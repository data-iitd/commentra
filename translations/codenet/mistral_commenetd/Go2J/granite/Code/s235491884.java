
// Package main is the entry point of the program
package main;

import java.util.Scanner;

// Function main is the entry point of the program
public class s235491884{
	public static void main(String[] args) {
		// Create a Scanner object to read input from the standard input
		Scanner scanner = new Scanner(System.in);
		// Read a string input from the standard input
		String s = scanner.nextLine();

		// Use's.length()' to get the length of the string's'
		int n = s.length();

		// Calculate the result by adding 700 to the product of 100 and the length of the string
		int result = 700 + n * 100;
		// Use 'System.out.println' to print the result to the standard output
		System.out.println(result);
	}
}

// The code ends here