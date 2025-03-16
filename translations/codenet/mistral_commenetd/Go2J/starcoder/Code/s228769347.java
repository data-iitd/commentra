// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

public class Main {

	// Function to initialize a new scanner for reading input
	public static Scanner getScanner(File fp) {
		// Creating a new scanner for reading the input
		Scanner scanner = new Scanner(fp);
		scanner.useDelimiter("\\s");
		return scanner;
	}

	// Function to read the next word as a string
	public static String getNextString(Scanner scanner) {
		scanner.next();
		return scanner.next();
	}

	// Function to read the next integer from the input
	public static int getNextInt(Scanner scanner) {
		return Integer.parseInt(scanner.next());
	}

	// Function to read the next integer64 from the input
	public static long getNextInt64(Scanner scanner) {
		return Long.parseLong(scanner.next());
	}

	// Function to read the next uint64 from the input
	public static long getNextUint64(Scanner scanner) {
		return Long.parseUnsignedLong(scanner.next());
	}

	// Function to read the next float64 from the input
	public static double getNextFloat64(Scanner scanner) {
		return Double.parseDouble(scanner.next());
	}

	// Main function to solve the problem
	public static void main(String[] args) {
		// Creating a new scanner for reading the input
		Scanner scanner = getScanner(new File(args[0]));

		// Reading the number of elements in the array
		int n = getNextInt(scanner);

		// Creating a slice of length n to store the elements
		int[] ll = new int[n];

		// Reading the elements of the array
		for (int i = 0; i < n; i++) {
			ll[i] = getNextInt(scanner);
		}

		// Sorting the slice in ascending order
		Arrays.sort(ll);

		// Initializing the answer variable to 0
		int ans = 0;

		// Iterating through all possible pairs of elements
		for (int i = 0; i < n-2; i++) {
			// Iterating through all possible right pointers
			for (int j = i + 1; j < n-1; j++) {
				// Initializing the left and right pointers for binary search
				int l = j + 1;
				int r = n;

				// Binary search to find the index of the element greater than the sum of the current pair
				while (l < r) {
					int m = (l + r) >> 1;
					if (ll[m] < ll[i]+ll[j]) {
						l = m + 1;
						continue;
					}
					r = m;
				}

				// Updating the answer variable
				ans += l - (j + 1);
			}
		}

		// Writing the answer to the output file
		System.out.println(ans);
	}
}

// "

Translate the above Java code to C++ and end with comment "