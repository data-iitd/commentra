package main;

import java.util.Scanner;

public class FenwickTree {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int q = in.nextInt();
		BIT bit = new BIT(n);
		for (int i = 0; i < n; i++) {
			bit.add(i, in.nextInt());
		}
		for (int i = 0; i < q; i++) {
			int t = in.nextInt();
			if (t == 0) {
				int p = in.nextInt();
				int x = in.nextInt();
				bit.add(p, x);
			} else {
				int l = in.nextInt();
				int r = in.nextInt();
				System.out.println(bit.sum(r) - bit.sum(l));
			}
		}
	}

	// BIT implementation

	// BIT represents the Fenwick Tree data structure.
	static class BIT {
		int n;
		int[] data;

		// FenwickTree initializes and returns a new Fenwick Tree with a given size.
		BIT(int n) {
			this.n = n;
			data = new int[n];
		}

		// Add updates the value at position p by adding x to it.
		void add(int p, int x) {
			p++; // Convert to 1-based index
			while (p <= n) {
				data[p-1] += x;
				p += p & -p; // Move to the next node
			}
		}

		// Sum calculates the sum of elements between indices l and r.
		int sum(int r) {
			int s = 0;
			while (r > 0) {
				s += data[r-1];
				r -= r & -r; // Move to the parent node
			}
			return s;
		}
	}
}

