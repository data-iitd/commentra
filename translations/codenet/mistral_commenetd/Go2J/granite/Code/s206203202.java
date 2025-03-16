
// Package main is the entry point of the program
package main;

import java.util.Scanner;

// Abs function returns the absolute value of an integer
public int Abs(int x) {
	if (x < 0) {
		// If the input integer is negative, return its negation
		return -x;
	}
	// Otherwise, return the input integer as it is
	return x;
}

// min function returns the minimum of two integers
public int min(int a, int b) {
	if (a > b) {
		// If the first integer is greater than the second, return the second
		return b;
	}
	// Otherwise, return the first integer
	return a;
}

// main function is the entry point of the program
public class s206203202{
	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner scanner = new Scanner(System.in);

		// Declare and initialize two integer variables, N and K, using scanner.nextInt
		int N = scanner.nextInt();
		int K = scanner.nextInt();

		// Declare and initialize an integer variable, x, with the value of N modulo K
		int x = N % K;

		// Call the Abs function to get the absolute value of x if it's negative
		x = Abs(x);

		// Call the min function to find the minimum between x and Abs(x-K)
		x = min(Abs(x-K), x);

		// Print the result using System.out.println
		System.out.println(x);

		// Close the Scanner object to release system resources
		scanner.close();
	}
}

