package main;

import java.util.*;

public class Main {
	// A helper function to print output
	public static void out(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	// Initialize a scanner for reading input
	static Scanner sc = new Scanner(System.in);

	// Function to read an integer from the standard input
	public static int getInt() {
		return Integer.parseInt(sc.next());
	}

	// Function to read a string from the standard input
	public static String getString() {
		return sc.next();
	}

	// Main function
	public static void main(String[] args) {
		// Initialize the scanner for reading input
		sc = new Scanner(System.in);

		// Read the number of elements 'n' and the number of queries 'q' from the standard input
		int n = getInt(), q = getInt();

		// Initialize a Fenwick Tree of size 'n'
		BIT fw = new BIT(n);

		// Iterate through each element and add it to the Fenwick Tree
		for (int i = 0; i < n; i++) {
			// Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
			int a = getInt();
			fw.add(i, a);
		}

		// Iterate through each query
		for (int i = 0; i < q; i++) {
			// Read an integer 't' from the standard input to determine the type of query
			int t = getInt();

			// If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
			if (t == 0) {
				int p = getInt(), x = getInt();
				fw.add(p, x);
			} else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
				int l = getInt(), r = getInt();
				// Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
				out(fw.sum(r) - fw.sum(l));
			}
		}
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	int[] data;

	public BIT(int n) {
		this.n = n;
		data = new int[n];
	}

	public void add(int p, int x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public int sum(int r) {
		int s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// END-OF-CODE

