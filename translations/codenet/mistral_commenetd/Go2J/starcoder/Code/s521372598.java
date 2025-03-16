// Package main is the entry point of the program

import (
	// Importing necessary packages
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

public class Main {
	// Main function
	public static void main(String[] args) {
		// Local variables
		int n; // Variable n is initialized to 0
		int[] as; // Variable as is initialized to an empty array
		int[] xs; // Variable xs is initialized to an empty array
		int b; // Variable b is initialized to 0
		int ans; // Variable ans is initialized to 0

		// Reading the number of elements in the array
		n = getInt();
		// Reading the array elements
		as = getIntSlice(n);
		// Initializing an array xs of size n
		xs = new int[n];
		// Iterating through the array as and assigning the value xs[i]
		for (int i = 0; i < n; i++) {
			xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
		}
		// Sorting the array xs in ascending order
		Arrays.sort(xs);
		// Assigning the middle element of the sorted array xs to variable b
		b = xs[n / 2];
		// Initializing variable ans with 0
		ans = 0;
		// Iterating through the array xs and calculating the absolute difference between each element and b
		for (int x : xs) {
			ans += Math.abs(x - b); // Calculating the absolute difference and adding it to ans
		}
		// Printing the answer
		System.out.println(ans);
	}

	// Function to calculate the absolute difference of a number
	public static int abs(int n) {
		// If the number is negative, return the negative number with the minus sign removed
		if (n < 0) {
			return -n;
		}
		// If the number is non-negative, return the number itself
		return n;
	}

	// -----------------------------------------

	public static int getInt() {
		// Function to read an integer from standard input
		return Integer.parseInt(getString());
	}

	public static int[] getIntSlice(int n) {
		// Function to read an array of n integers from standard input
		int[] ret = new int[n]; // Initialize the array with size n
		for (int i = 0; i < n; i++) {
			ret[i] = getInt(); // Read each integer and assign it to the corresponding index in the array
		}
		return ret;
	}

	public static String getString() {
		// Function to read a string from standard input
		return br.readLine();
	}

	public static void getRunes() {
		// Function to read a rune string from standard input
		return;
	}

	// -----------------------------------------

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Buffered reader for standard input
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // Buffered writer for standard output
}

