
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable named "s" of type string
		String s;

		// Use the "new Scanner(System.in)" function to read a string input from the standard input
		Scanner sc = new Scanner(System.in);
		s = sc.next();

		// Check if the length of the string "s" is greater than or equal to 4
		// and if its first four characters are "YAKI"
		if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
			// If the condition is true, print the word "Yes" to the standard output
			System.out.println("Yes");
		} else {
			// If the condition is false, print the word "No" to the standard output
			System.out.println("No");
		}
	}
}

