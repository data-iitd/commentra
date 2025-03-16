
package main;

import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Arrays;

//=====I/O=====

// Declare scanner and writer for input and output
Scanner sc = new Scanner(System.in);
PrintWriter wr = new PrintWriter(System.out);

// Function to scan an integer from input
int scanInt() {
	sc.next(); // Read the next token
	return Integer.parseInt(sc.next()); // Convert the token to an integer
}

// Function to scan a 64-bit integer from input
long scanInt64() {
	sc.next(); // Read the next token
	return Long.parseLong(sc.next()); // Convert the token to a 64-bit integer
}

// Function to scan multiple integers from input
int[] scanInts(int n) {
	int[] res = new int[n]; // Create a slice to hold n integers
	for (int i = 0; i < n; i++) {
		res[i] = scanInt(); // Fill the slice with integers from input
	}
	return res; // Return the slice of integers
}

// Function to scan a single line of text from input
String scanText() {
	sc.next(); // Read the next token
	return sc.next(); // Return the text
}

// Function to print integers to output
void printInts(int... a) {
	for (int i = 0; i < a.length; i++) {
		wr.print(a[i]); // Print each integer
		if (i != a.length - 1) {
			wr.print(" "); // Print space between integers
		}
	}
	wr.println(); // Print a newline after all integers
	wr.flush(); // Flush the writer to ensure all output is written
}

//=====main=====

// Main function where execution starts
public static void main(String[] args) {
	sc.useDelimiter("\\s+"); // Set the scanner to split input by words

	int n = scanInt(); // Read the number of integers

	int[] c = scanInts(n); // Read n integers into slice c

	int ans = 0; // Initialize answer variable
	Arrays.sort(c); // Sort the slice of integers

	// Calculate the answer based on the sorted integers
	for (int i = 0; i < n; i++) {
		ans = (ans + (n+1-i)*c[i]%mod) % mod; // Update the answer using the formula
	}

	// Print the final result after applying modular exponentiation
	System.out.println(ans * modpow(4, n-1) % mod);
}

final int mod = 1000000007; // Define a constant for the modulus

// Function to perform modular exponentiation
int modpow(int a, int n) {
	int res = 1; // Initialize result
	for (; n > 0; n >>= 1) {
		if (n % 2 == 1) { // If n is odd
			res = res * a % mod; // Update result
		}
		a = a * a % mod; // Square the base
	}
	return res; // Return the final result
}

