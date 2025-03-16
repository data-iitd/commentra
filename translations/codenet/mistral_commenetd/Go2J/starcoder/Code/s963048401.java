
import java.util.*;
import java.io.*;

public class Main {

	// Initialize a scanner for reading input from stdin
	static Scanner sc = new Scanner(System.in);

	// Function to read a single string from stdin and return it
	static String readString() {
		return sc.next();
	}

	// Function to read an integer from stdin and return it
	static int readInt() {
		return Integer.parseInt(readString());
	}

	// Function to read a floating point number from stdin and return it
	static double readFloat() {
		return Double.parseDouble(readString());
	}

	// Function to convert a string to an integer
	static int stringToInt(String s) {
		return Integer.parseInt(s);
	}

	// Initialize the modulus value
	static int mod = 1000000007;

	// Initialize a buffer to store the unique elements
	static int[] buf = new int[mod];

	// Function to read input and process it
	public static void main(String[] args) {
		// Initialize the scanner buffer and split function for the scanner
		sc.useDelimiter("\\s");

		// Read the number of elements in the array
		int n = readInt();

		// Initialize an array of size n to store the elements
		int[] as = new int[n];

		// Read the elements of the array into the as slice
		for (int i = 0; i < n; i++) {
			as[i] = readInt();
		}

		// Initialize an empty slice xs to store the unique elements
		int[] xs = new int[1];
		xs[0] = as[0];

		// Iterate through the array and add unique elements to the xs slice
		for (int j = 1; j < n; j++) {
			// Binary search to find the index where the current element should be inserted in the xs slice
			int idx = Arrays.binarySearch(xs, 0, xs.length, as[j]);

			// If the current element is not already present in the xs slice, append it
			if (idx < 0) {
				xs = Arrays.copyOf(xs, xs.length + 1);
				xs[xs.length - 1] = as[j];
			} else {
				// Otherwise, replace the element at the found index with the current element
				xs[idx] = as[j];
			}
		}

		// Print the length of the xs slice
		System.out.println(xs.length);
	}
}

