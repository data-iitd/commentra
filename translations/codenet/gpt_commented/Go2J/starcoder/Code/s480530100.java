package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read the number of elements (n) and the number of queries (q).
		int n = sc.nextInt();
		int q = sc.nextInt();

		// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
		BIT fw = new BIT(n);

		// Read n integers and add them to the Fenwick Tree.
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			fw.add(i, a);
		}

		// Process q queries.
		for (int i = 0; i < q; i++) {
			int t = sc.nextInt(); // Read the type of query.
			if (t == 0) {
				// For update queries, read position (p) and value (x) and update the Fenwick Tree.
				int p = sc.nextInt();
				int x = sc.nextInt();
				fw.add(p, x);
			} else {
				// For sum queries, read the range (l, r) and output the sum from l to r.
				int l = sc.nextInt();
				int r = sc.nextInt();
				System.out.println(fw.sum(r) - fw.sum(l));
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

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
	int n; // Number of elements in the tree
	int[] data; // Array to store the tree data

	// FenwickTree initializes a new Binary Indexed Tree with n elements.
	public BIT(int n) {
		this.n = n;
		data = new int[n]; // Create a slice to hold the tree data
	}

	// Add updates the Fenwick Tree by adding x to the element at position p.
	public void add(int p, int x) {
		p++; // Increment p to match the 1-based index used in Fenwick Tree
		while (p <= n) {
			data[p-1] += x; // Update the tree data
			p += p & -p; // Move to the next index
		}
	}

	// Sum calculates the sum of elements in the range [l, r).
	public int sum(int r) {
		return sum(r, 0, n);
	}

	// sum calculates the prefix sum from the start to index r.
	public int sum(int r, int start, int end) {
		int s = 0; // Initialize sum
		while (r > 0) {
			s += data[r-1]; // Add the value at index r-1
			r -= r & -r; // Move to the parent index
		}
		return s; // Return the calculated sum
	}
}

