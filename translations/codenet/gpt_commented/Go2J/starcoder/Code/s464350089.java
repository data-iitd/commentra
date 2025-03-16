package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a scanner for reading input
		Scanner sc = new Scanner(System.in);

		// Read the values of h and n from input
		int h = sc.nextInt();
		int n = sc.nextInt();

		// Initialize a variable to accumulate the sum of integers
		int a = 0;

		// Loop to read n integers and accumulate their sum
		for (int i = 0; i < n; i++) {
			a += sc.nextInt();
		}

		// Check if the accumulated sum is less than h
		if (h > a) {
			// If h is greater than the sum, print "No"
			System.out.println("No");
		} else {
			// Otherwise, print "Yes"
			System.out.println("Yes");
		}
	}
}

