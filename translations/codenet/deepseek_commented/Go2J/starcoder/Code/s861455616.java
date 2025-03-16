package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a string variable to store user input
		String s;
		
		// Read a string input from the user and store it in `s`
		Scanner sc = new Scanner(System.in);
		s = sc.next();
		
		// Check if the length of `s` is at least 4 and if the first four characters are "YAKI"
		if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
			// If the condition is true, print "Yes"
			System.out.println("Yes");
		} else {
			// Otherwise, print "No"
			System.out.println("No");
		}
	}
}

