
// Package main is the entry point of the program
package main

import java.io.BufferedReader; // Import java.io.BufferedReader for reading input
import java.io.InputStreamReader; // Import java.io.InputStreamReader for reading input
import java.io.IOException; // Import java.io.IOException for error handling
import java.util.Arrays; // Import java.util.Arrays for sorting
import java.util.StringTokenizer; // Import java.util.StringTokenizer for tokenizing strings

// Constants and variables declaration
final int inf = Integer.MAX_VALUE; // Constants for maximum signed integer value

// var mod = 1000000007; // Unused constant, can be removed

// Global variables declaration
BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Global buffered reader for reading input

// init function initializes the program
static {
	System.setErr(System.out); // Set error stream to output stream
}

// main function is the entry point of the program
public static void main(String[] args) throws IOException {
	// Read input N as a string
	String N = br.readLine();
	// Convert N to an integer
	int n = Integer.parseInt(N);
	// Check if m is divisible by n
	if (n % m == 0) {
		System.out.println("Yes"); // Print "Yes" if m is divisible by n
	} else {
		System.out.println("No"); // Print "No" if m is not divisible by n
	}
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
class Pair {
	int a, b;

	// Constructor for initializing a Pair
	public Pair(int a, int b) {
		this.a = a;
		this.b = b;
	}
}

// Pairs type definition for storing a slice of Pair
class Pairs {
	Pair[] pairs;

	// Constructor for initializing a Pairs
	public Pairs(Pair[] pairs) {
		this.pairs = pairs;
	}
}

// Implement compareTo method for sorting Pairs based on the second element
public int compareTo(Pair p) {
	return this.b - p.b; // Sort based on the second element
}

// ------int methods-------------------------
public static boolean in(int c, int a, int z) {
	return c >= a && c < z; // Check if c is within the range [a, z)
}
public static boolean out(int c, int a, int z) {
	return !in(c, a, z); // Check if c is outside the range [a, z)
}
public static int btoi(boolean b) {
	if (b) {
		return 1; // Convert boolean to integer: 1 for true, 0 for false
	}
	return 0;
}
public static boolean itob(int a) {
	return a != 0; // Convert integer to boolean: true for non-zero, false for zero
}
public static int max(int... a) {
	int r = a[0];
	for (int i = 0; i < a.length; i++) {
		if (r < a[i]) {
			r = a[i]; // Find the maximum integer among the given integers
		}
	}
	return r;
}
public static int min(int... a) {
	int r = a[0];
	for (int i = 0; i < a.length; i++) {
		if (r > a[i]) {
			r = a[i]; // Find the minimum integer among the given integers
		}
	}
	return r;
}
public static int sum(int[] a) {
	int r = 0;
	for (int i = 0; i < a.length; i++) {
		r += a[i]; // Calculate the sum of all integers in the given slice
	}
	return r;
}
public static int pro(int[] a) {
	int r = a[0];
	for (int i = 1; i < a.length; i++) {
		r *= a[i]; // Calculate the product of all integers in the given slice
	}
	return r;
}

public static int[] fill(int[] a, int n) {
	for (int i = 0; i < a.length; i++) {
		a[i] = n; // Fill the given slice with the given integer value
	}
	return a;
}
public static int[] minmax(int a, int b) {
	if (a > b) {
		return new int[] { b, a }; // Return the minimum and maximum integers among the given integers
	}
	return new int[] { a, b };
}

public static int abs(int a) {
	if (a < 0) {
		return -a; // Calculate the absolute value of an integer
	}
	return a;
}

// ---------- buffered scanner -----------------------------------------
class scanner {
	BufferedReader r; // BufferedReader for reading input
	String buf; // Buffer for storing the input line
	int p; // Position in the buffer

	// Constructor for initializing a scanner
	public scanner() {
		r = new BufferedReader(new InputStreamReader(System.in)); // Initialize a new BufferedReader with a buffer size of 10000
	}
	public String next() {
		pre();
		int start = p;
		for (; p < buf.length(); p++) {
			if (buf.charAt(p) == ' ') {
				break; // Find the position of the next whitespace character
			}
		}
		String result = buf.substring(start, p); // Extract the substring from the buffer
		p++; // Increment the position in the buffer
		return result;
	}
	public String Line() {
		pre();
		int start = p;
		p = buf.length();
		String result = buf.substring(start); // Extract the rest of the line as a string
		return result;
	}
	public String String() {
		return next(); // Call next() method to read the next token as a string
	}
	public int Int() {
		int v = Integer.parseInt(next()); // Convert the next token to an integer
		return v;
	}
	public int[] Ints(int n) {
		int[] r = new int[n]; // Initialize an empty slice of integers with the given size
		for (int i = 0; i < n; i++) {
			r[i] = Int(); // Read and store n integers in the slice
		}
		return r;
	}
	public long Int64() {
		long v = Long.parseLong(next());
		return v;
	}
	public long Uint64() {
		long v = Long.parseLong(next());
		return v;
	}
	public double Float64() {
		double v = Double.parseDouble(next());
		return v;
	}
	public void pre() {
		if (p >= buf.length()) {
			readLine(); // Read a new line if the buffer is empty
			p = 0;
		}
	}
	public void readLine() {
		buf = ""; // Clear the buffer
		for (;;) {
			String l;
			try {
				l = r.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				return;
			}
			buf += l; // Append the read line to the buffer
			if (!l.contains(" ")) {
				break; // Exit the loop if the end of the input is reached
			}
		}
	}
}

