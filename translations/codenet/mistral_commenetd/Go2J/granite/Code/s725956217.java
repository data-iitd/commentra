
// Package main is the entry point of the program
package main;

import java.util.*;

// Class s725956217 is the entry point of the program
class s725956217 {
	// Function main is the entry point of the program
	public static void main(String[] args) {
		// Initialize the scanner for reading input from the standard input
		Scanner sc = new Scanner(System.in);

		// Read the number of shops N and the number of customers M from the standard input
		int N = sc.nextInt();
		int M = sc.nextInt();
		// Initialize a list of shop data structures named s with a capacity of N
		List<Shop> s = new ArrayList<Shop>(N);
		// For each shop in the list
		for (int i = 0; i < N; i++) {
			// Read the capacity 'a' and demand 'b' of the shop from the standard input
			int a = sc.nextInt();
			int b = sc.nextInt();
			// Create a new shop data structure with the read values and add it to the list
			s.add(new Shop(a, b));
		}
		// Sort the list of shops in ascending order based on the 'a' field of each shop
		Collections.sort(s);

		// Initialize a variable named total to store the total capacity used by the shops
		int total = 0;
		// For each shop in the sorted list
		for (Shop e : s) {
			// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
			int n = Math.min(e.b, M);
			// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
			total += n * e.a;
			// Decrease the maximum demand by the number of customers served by the shop
			M -= n;
			// If the maximum demand becomes zero, break the loop
			if (M == 0) {
				break;
			}
		}
		// Print the total capacity used by the shops
		System.out.println(total);
	}
}

// Class Shop represents a data structure for storing two integers
class Shop implements Comparable<Shop> {
	// Fields 'a' and 'b' store the capacity and demand of the shop, respectively
	int a, b;

	// Constructor for creating a new shop data structure with the given capacity and demand
	public Shop(int a, int b) {
		this.a = a;
		this.b = b;
	}

	// Method compareTo compares two shop data structures and returns a negative, zero, or positive integer depending on their relative order
	@Override
	public int compareTo(Shop o) {
		return this.a - o.a;
	}
}

// End of code.