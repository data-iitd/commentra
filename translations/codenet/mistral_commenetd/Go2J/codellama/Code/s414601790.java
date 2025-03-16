// Package declaration
package main;

// Importing the 'Scanner' class for input/output operations
import java.util.Scanner;

public class Main {
	// Main method
	public static void main(String[] args) {
		// Creating an object of the 'Scanner' class
		Scanner sc = new Scanner(System.in);

		// Variable declaration and initialization
		int n = sc.nextInt();
		String s = sc.next();

		// Variable declaration and initialization for maximum count and current count
		int max = 0;
		int cnt = 0;

		// Iterating through each character in the string 's'
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
	}
}

