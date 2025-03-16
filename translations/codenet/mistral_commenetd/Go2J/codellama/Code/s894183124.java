// Package main is the entry point of our Java program
package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Declare and initialize two variables: n of type int and s of type String
		int n;
		String s;

		// Use the Scanner class to read input from the standard input
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		s = scanner.next();

		// Use the String class to compute and print the result
		System.out.println(s.length() - s.replace("ABC", "").length());
	}
}

// End of code 