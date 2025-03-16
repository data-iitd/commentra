package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize the scanner to read input from standard input
		Scanner sc = new Scanner(System.in);

		// Read the input string
		String s = sc.next();

		// Start checking for the first missing lowercase letter from 'a'
		char c = 'a';

		// Loop through all lowercase letters from 'a' to 'z'
		for (int j = 0; j < 26; j++) {
			boolean found = false; // Flag to check if the current letter is found in the input string
			// Check if the current letter exists in the input string
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == c) {
					found = true; // Set the flag to true if the letter is found
					break;
				}
			}
			// If the letter was not found, print it and exit
			if (found == false) {
				System.out.println(c);
				return;
			}
			c++; // Move to the next letter
		}

		// If all letters from 'a' to 'z' are found, print "None"
		System.out.println("None");
	}
}

// 