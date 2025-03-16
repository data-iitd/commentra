
// Package main is the entry point of the program
package main

import java.util.Scanner; // Import Scanner class for reading standard input

// Function to read an integer from standard input
int nextInt() {
	return sc.nextInt(); // Return next integer
}

// Function to read a string from standard input
String nextStr() {
	return sc.next(); // Return next string
}

// Main function
public static void main(String[] args) {
	// Initialize scanner
	Scanner sc = new Scanner(System.in);

	// Read the first string from standard input
	String s = nextStr();

	// Initialize variable c with 'a'
	char c = 'a';

	// Check all characters from 'a' to 'z' in the string s
	for (int j = 0; j < 26; j++) {
		// Initialize variable found as false
		boolean found = false;

		// Iterate through each character in the string s
		for (int i = 0; i < s.length(); i++) {
			// If current character matches c, set found to true and break the loop
			if (s.charAt(i) == c) {
				found = true;
				break;
			}
		}

		// If character c is not found in the string s, print it and return
		if (found == false) {
			System.out.println(c);
			return;
		}

		// Increment variable c
		c++;
	}

	// If no character from 'a' to 'z' is found in the string s, print "None"
	System.out.println("None");
}

