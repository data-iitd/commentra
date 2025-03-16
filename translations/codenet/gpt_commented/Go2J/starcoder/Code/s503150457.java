package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three string variables to hold user input
		String s1, s2, s3;
		
		// Read three strings from standard input
		Scanner sc = new Scanner(System.in);
		s1 = sc.next();
		s2 = sc.next();
		s3 = sc.next();
		
		// Split each string into a slice of individual characters
		String[] s1s = s1.split("");
		String[] s2s = s2.split("");
		String[] s3s = s3.split("");
		
		// Convert the first character of each string to uppercase and concatenate them
		String result = s1s[0].toUpperCase() + s2s[0].toUpperCase() + s3s[0].toUpperCase();
		
		// Print the concatenated result
		System.out.println(result);
	}
}

