
// Package main is the entry point of the program.
package main;

import java.util.*; // We use Scanner class for reading input.

// out is a custom function for printing output.
void out(Object... x) {
	System.out.println(Arrays.deepToString(x));
}

// main is the entry point of the program.
public class s236040683{
	public static void main(String[] args) {
		// Set up the scanner to read words instead of lines.
		Scanner sc = new Scanner(System.in).useDelimiter("\\s+");

		// Read the number of nodes N and edges M from the input.
		int N = sc.nextInt(), M = sc.nextInt();

		// Create a 2D array n of size N x N to store the adjacency matrix.
		boolean[][] n = new boolean[N][N];

		// Process each edge by adding it to the adjacency matrix.
		for (int i = 0; i < M; i++) {
			// Read the from and to nodes from the input.
			int from = sc.nextInt() - 1, to = sc.nextInt() - 1;

			// Add the edge to the adjacency matrix.
			n[from][to] = n[to][from] = true;
		}

		// Print the number of neighbors for each node.
		for (int i = 0; i < N; i++) {
			// Initialize a counter to count the number of neighbors.
			int count = 0;

			// Iterate over the adjacency matrix to count the number of neighbors.
			for (int j = 0; j < N; j++) {
				if (n[i][j]) {
					count++;
				}
			}

			// Print the number of neighbors of the current node.
			out(count);
		}
	}
}

// 