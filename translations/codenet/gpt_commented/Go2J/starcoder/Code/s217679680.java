package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Create a new scanner to read from standard input
		Scanner stdin = new Scanner(System.in);
		// Read an array of integers from standard input
		int[] arr = scanArrayInt(stdin);
		// Assign the first two elements of the array to variables a and b
		int a = arr[0], b = arr[1];
		// Initialize the number of taps needed to 0
		int tap = 0;
		// Initialize the consent variable to 1 (the starting point)
		int consent = 1;
		
		// Loop until the consent value is less than b
		while (consent < b) {
			// Update consent by adding (a - 1) to it
			consent = consent + a - 1;
			// Increment the tap count
			tap++;
		}
		
		// Print the total number of taps needed
		System.out.println(tap);
	}

	// Function to scan an array of integers from standard input
	public static int[] scanArrayInt(Scanner stdin) {
		// Initialize an empty array to hold the integers
		int[] ret = new int[0];
		// Read a line from standard input
		stdin.nextLine();
		// Split the input line into strings and convert each to an integer
		String[] s = stdin.nextLine().split(" ");
		for (int i = 0; i < s.length; i++) {
			ret = Arrays.copyOf(ret, ret.length + 1);
			ret[ret.length - 1] = Integer.parseInt(s[i]);
		}
		// Return the array of integers
		return ret;
	}
}

