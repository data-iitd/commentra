// Package declaration
package main;

import java.util.*;

// Importing the 'java.util.*' package for input/output operations

public class Main {

	public static void main(String[] args) {
		// Creating a Scanner object for reading input from the user
		Scanner sc = new Scanner(System.in);

		// Variable declaration and initialization
		int n = sc.nextInt();
		String s = sc.next();

		// Variable declaration and initialization for maximum count and current count
		int max = 0;
		int cnt = 0;

		// Iterating through each character in the string's'
		for (int i = 0; i < s.length(); i++) {
			// Checking if the character is 'I'
			if (s.charAt(i) == 'I') {
				// Incrementing the current count
				cnt++;
			} else {
				// Decrementing the current count
				cnt--;
			}

			// Updating the maximum count if the current count is greater
			if (cnt > max) {
				max = cnt;
			}
		}

		// Printing the maximum count
		System.out.println(max);

		// Closing the Scanner object
		sc.close();
	}
}

