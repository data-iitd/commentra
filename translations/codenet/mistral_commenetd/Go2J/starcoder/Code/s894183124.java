// Package main is the entry point of our Java program

import (
	// We import the "java.util.Scanner" class to enable input/output operations
	import java.util.Scanner;
	// We import the "java.lang.String" class to use the "count" function
	import java.lang.String;
)

public class Main {

	public static void main(String[] args) {
		// Declare and initialize two variables: n of type int and s of type String
		int n;
		String s;

		// Use the Scanner class to read input from the standard input
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		s = input.next();

		// Use the System.out and String classes to compute and print the result
		System.out.println(String.count(s, "ABC"));
	}

}

// End of code

