
// Package declaration
package main;

import java.util.Scanner;
// Importing the 'Scanner' class from the 'java.util' package for input/output operations

public class s414601790{
	public static void main(String[] args) {
		// Variable declaration and initialization
		int n;
		String s;

		// Creating a new instance of the 'Scanner' class to read input from the user
		Scanner scanner = new Scanner(System.in);

		// Reading input from the user
		n = scanner.nextInt();
		s = scanner.next();

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

		// Closing the 'Scanner' object to release system resources
		scanner.close();
	}
}

// End of the code