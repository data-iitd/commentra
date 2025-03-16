// Package main is the entry point of the program
package main;

import java.util.Scanner;

// Class shop represents a data structure for storing two integers
class shop {
	int a, b;
	// Constructor
	shop(int a, int b) {
		this.a = a;
		this.b = b;
	}
}

// Class Datas is a slice of shop data structures
class Datas extends ArrayList<shop> {
	// Constructor
	public Datas(int n) {
		super(n);
	}
}

// Function out is used for printing output to the console
public static void out(Object... x) {
	System.out.println(Arrays.deepToString(x));
}

// Function getInt is used for reading an integer value from the standard input
public static int getInt() {
	return new Scanner(System.in).nextInt();
}

// Function getString is used for reading a string value from the standard input
public static String getString() {
	return new Scanner(System.in).next();
}

// Function max returns the maximum value between two integers
public static int max(int a, int b) {
	// If the first integer is greater than the second integer, return the first integer
	if (a > b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function min returns the minimum value between two integers
public static int min(int a, int b) {
	// If the first integer is less than the second integer, return the first integer
	if (a < b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function asub returns the absolute difference between two integers
public static int asub(int a, int b) {
	// If the first integer is greater than the second integer, return the difference
	if (a > b) {
		return a - b;
	}
	// Otherwise, return the negative difference
	return b - a;
}

// Function abs returns the absolute value of an integer
public static int abs(int a) {
	// If the integer is greater than or equal to zero, return the integer itself
	if (a >= 0) {
		return a;
	}
	// Otherwise, return the negative of the integer
	return -a;
}

// Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
public static int lowerBound(int[] a, int x) {
	// Use the Arrays.binarySearch function to find the index
	int idx = Arrays.binarySearch(a, x);
	// If the index is less than zero, add one to it
	if (idx < 0) {
		idx = -idx - 1;
	}
	// Return the index
	return idx;
}

// Function upperBound returns the index of the first element in the slice that is greater than the given value
public static int upperBound(int[] a, int x) {
	// Use the Arrays.binarySearch function to find the index
	int idx = Arrays.binarySearch(a, x);
	// If the index is less than zero, add one to it
	if (idx < 0) {
		idx = -idx - 1;
	}
	// If the index is greater than or equal to the length of the slice, return the length of the slice
	if (idx >= a.length) {
		return a.length;
	}
	// Otherwise, return the index plus one
	return idx + 1;
}

// Main function is the entry point of the program
public static void main(String[] args) {
	// Initialize the scanner for reading input from the standard input
	Scanner sc = new Scanner(System.in);
	sc.useDelimiter("[^0-9]+");

	// Read the number of shops N and the number of customers M from the standard input
	int N = sc.nextInt();
	int M = sc.nextInt();
	// Initialize a slice of shop data structures named s with a length of N
	Datas s = new Datas(N);
	// For each shop in the slice
	for (int i = 0; i < N; i++) {
		// Read the capacity 'a' and demand 'b' of the shop from the standard input
		int a = sc.nextInt();
		int b = sc.nextInt();
		// Create a new shop data structure with the read values and assign it to the i-th position in the slice
		s.set(i, new shop(a, b));
	}
	// Sort the slice in ascending order based on the 'a' field of each shop
	s.sort(Comparator.comparingInt(shop::getA));

	// Initialize a variable named total to store the total capacity used by the shops
	int total = 0;
	// For each shop in the sorted slice
	for (shop e : s) {
		// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		int n = min(e.b, M);
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
	out(total);
}

