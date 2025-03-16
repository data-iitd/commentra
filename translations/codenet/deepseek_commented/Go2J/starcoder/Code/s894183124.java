package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Declare variables to store the input values.
		// `n` will store the integer input and `s` will store the string input.
		int n = sc.nextInt();
		String s = sc.next();
		
		// Read an integer `n` and a string `s` from the standard input.
		// The format specifier "%d" is used to read an integer, and "%s" is used to read a string.
		
		// Print the number of occurrences of the substring "ABC" in the string `s`.
		// The `strings.Count` function is used to count the occurrences of the substring "ABC".
		System.out.println(s.length() - s.replace("ABC", "").length());
	}
}

