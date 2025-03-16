
// Package main is the entry point of the program
package main;

import java.util.Scanner; // Import Scanner class for reading input

// s726858931 function
public class s726858931{
	public static void main(String[] args) {
		// Initialize scanner
		Scanner sc = new Scanner(System.in);

		// Read the first string from standard input
		String s = sc.next();

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
			if (!found) {
				System.out.println(c);
				return;
			}

			// Increment variable c
			c++;
		}

		// If no character from 'a' to 'z' is found in the string s, print "None"
		System.out.println("None");
	}
}

