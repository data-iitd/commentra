
// Package main is the entry point of the program
package main

// Import the Scanner class for reading input from the standard input
import java.util.Scanner;

// Function out is used for printing output to the console
public static void out(Object... x) {
	System.out.println(x);
}

// Function getInt is used for reading an integer value from the standard input
public static int getInt() {
	// Create a new Scanner object for reading input from the standard input
	Scanner sc = new Scanner(System.in);
	// Read the next integer value from the standard input
	int i = sc.nextInt();
	// Return the read integer value
	return i;
}

// Function getString is used for reading a string value from the standard input
public static String getString() {
	// Create a new Scanner object for reading input from the standard input
	Scanner sc = new Scanner(System.in);
	// Read the next string value from the standard input
	String s = sc.next();
	// Return the read string value
	return s;
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

// Function lowerBound returns the index of the first element in the array that is greater than or equal to the given value
public static int lowerBound(int[] a, int x) {
	// Use the Arrays.binarySearch function to find the index
	int idx = Arrays.binarySearch(a, x);
	// If the index is negative, return the negative of the index
	if (idx < 0) {
		return -idx - 1;
	}
	// Otherwise, return the index
	return idx;
}

// Function upperBound returns the index of the first element in the array that is greater than the given value
public static int upperBound(int[] a, int x) {
	// Use the Arrays.binarySearch function to find the index
	int idx = Arrays.binarySearch(a, x);
	// If the index is negative, return the negative of the index
	if (idx < 0) {
		return -idx - 1;
	}
	// Otherwise, return the index
	return idx;
}

// Class shop represents a data structure for storing two integers
class shop {
	// Declare two integer fields named a and b
	int a, b;

	// Constructor for creating a new shop data structure
	public shop(int a, int b) {
		// Initialize the fields with the given values
		this.a = a;
		this.b = b;
	}
}

// Class Datas is a class for storing an array of shop data structures
class Datas {
	// Declare an integer field named N
	int N;
	// Declare an array of shop data structures named s
	shop[] s;

	// Constructor for creating a new Datas object
	public Datas(int N) {
		// Initialize the field with the given value
		this.N = N;
		// Initialize the array with a length of N
		s = new shop[N];
	}

	// Function Len returns the length of the array
	public int Len() {
		// Return the length of the array
		return N;
	}

	// Function Swap swaps the positions of two elements in the array
	public void Swap(int i, int j) {
		// Swap the positions of the two elements
		shop temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	// Function Less compares two shop data structures and returns true if the first one should come before the second one in a sorted array
	public boolean Less(int i, int j) {
		// Compare the 'a' fields of the two shop structures
		return s[i].a < s[j].a;
	}
}

// Main function is the entry point of the program
public class Main {
	public static void main(String[] args) {
		// Read the number of shops N and the number of customers M from the standard input
		int N, M = getInt(), getInt();
		// Initialize a new Datas object named s with a length of N
		Datas s = new Datas(N);
		// For each shop in the array
		for (int i = 0; i < N; i++) {
			// Read the capacity 'a' and demand 'b' of the shop from the standard input
			int a, b = getInt(), getInt();
			// Create a new shop data structure with the read values and assign it to the i-th position in the array
			s.s[i] = new shop(a, b);
		}
		// Sort the array in ascending order based on the 'a' field of each shop
		s.Sort();

		// Initialize a variable named total to store the total capacity used by the shops
		int total = 0;
		// For each shop in the sorted array
		for (int i = 0; i < N; i++) {
			// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
			int n = min(s.s[i].b, M);
			// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
			total += n * s.s[i].a;
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
}

