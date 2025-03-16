// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class Main {
	// Creating a new scanner instance
	static Scanner sc = new Scanner(System.in);

	// Main function
	public static void main(String[] args) {
		// Reading the first integer from the standard input
		int n = sc.nextInt();
		// Initializing the answer variable
		double ans = 0.0;

		// Iterating through the given number of integers
		for (int i = 0; i < n; i++) {
			// Reading the next integer from the standard input
			int tmp = 1 / sc.nextInt();
			// Adding the reciprocal of the current integer to the answer
			ans += tmp;
		}

		// Printing the final answer
		System.out.printf("%.10f\n", 1 / ans);
	}
}

// 