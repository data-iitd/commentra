package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable to hold the input string
		String s;
		// Read input from the user
		Scanner sc = new Scanner(System.in);
		s = sc.next();

		// Initialize a counter for consecutive valid characters and a slice to hold counts
		int count = 0;
		int[] counter = new int[1];

		// If the input string is empty, exit the function
		if (s.equals("")) {
			return;
		}

		// Start the counter with an initial value of 0
		counter[0] = 0;
		// Split the input string into a slice of individual characters
		String[] li = s.split("");

		// Iterate over each character in the slice
		for (int i = 0; i < li.length; i++) {
			// Check if the character is one of the valid DNA bases
			if (li[i].equals("A") || li[i].equals("C") || li[i].equals("G") || li[i].equals("T")) {
				// Increment the count for consecutive valid characters
				count++;
			} else {
				// If an invalid character is encountered, store the current count
				counter = (int[]) append(counter, count);
				// Reset the count for the next sequence
				count = 0;
			}
		}

		// Append the count of the last sequence of valid characters
		counter = (int[]) append(counter, count);
		// Sort the counts to find the maximum consecutive valid characters
		Arrays.sort(counter);
		// Print the maximum count of consecutive valid characters
		System.out.println(counter[counter.length - 1]);
	}
}

