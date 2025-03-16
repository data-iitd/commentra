package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable 'n' of type string
		String n;

		// Read a string input from the user using Scanner.next()
		Scanner sc = new Scanner(System.in);
		n = sc.next();

		// Initialize a loop counter 'i'
		int i = 0;

		// Check if the current character in the string 'n' is equal to '7'
		while (i < 3 && n.charAt(i)!= '7') {
			i++;
		}

		// If no '7' is found in the first three characters, print "No"
		if (i == 3) {
			System.out.println("No");
		} else {
			// If yes, print "Yes" and exit the function
			System.out.println("Yes");
		}
	}
}

