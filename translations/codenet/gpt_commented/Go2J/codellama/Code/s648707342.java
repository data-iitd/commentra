
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a scanner to read input from standard input
		Scanner sc = new Scanner(System.in);

		// Function to scan an integer from input
		int scanInt() {
			sc.next(); // Read the next token from input
			int iv = Integer.parseInt(sc.next()); // Convert the token to an integer
			return iv; // Return the integer value
		}

		// Initialize the scanner to split input by whitespace
		void init() {
			sc.useDelimiter("\\s+");
		}

		// Main function where the program execution begins
		void main() {
			// Read the number of arms
			int n = scanInt();

			// Define a struct to represent an arm with left and right bounds
			class arm {
				int l, r;
			}

			// Create a slice to hold the arms
			arm[] as = new arm[n];

			// Read the arm data from input
			for (int i = 0; i < n; i++) {
				int x = scanInt(); // Read the center of the arm
				int l = scanInt(); // Read the length of the arm
				as[i].l = x - l; // Calculate the left bound
				as[i].r = x + l; // Calculate the right bound
			}

			// Sort the arms based on their right bounds
			sort(as, (a, b) -> a.r - b.r);

			// Initialize the count of non-overlapping arms and the rightmost bound
			int ans = 1; // Start with the first arm
			int r = as[0].r; // Set the rightmost bound to the right of the first arm

			// Iterate through the sorted arms to count non-overlapping arms
			for (int i = 1; i < n; i++) {
				// If the left bound of the current arm is greater than or equal to the rightmost bound
				if (as[i].l >= r) {
					ans++; // Increment the count of non-overlapping arms
					r = as[i].r; // Update the rightmost bound to the current arm's right bound
				}
			}

			// Print the total count of non-overlapping arms
			System.out.println(ans);
		}
	}
}

