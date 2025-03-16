// Package main is the entry point of the program.
package main;

import java.util.Scanner;

// Node is a custom data structure for representing a node in the graph.
class Node {
	int[] to;
}

// main is the entry point of the program.
public class Main {
	// sc is a buffer scanner for reading input.
	static Scanner sc = new Scanner(System.in);

	// out is a custom function for printing output.
	static void out(Object... o) {
		System.out.println(o);
	}

	// getInt reads and converts an integer from the input.
	static int getInt() {
		return Integer.parseInt(sc.next());
	}

	// getString reads and returns a string from the input.
	static String getString() {
		return sc.next();
	}

	// main is the entry point of the program.
	public static void main(String[] args) {
		// Set up the scanner to read words instead of lines.
		sc.useDelimiter("\\s+");

		// Read the number of nodes N and edges M from the input.
		int N = getInt(), M = getInt();

		// Create a slice n of size N to store the nodes.
		Node[] n = new Node[N];

		// Process each edge by adding it to the to slice of the corresponding nodes.
		for (int i = 0; i < M; i++) {
			// Read the from and to nodes from the input.
			int from = getInt() - 1, to = getInt() - 1;

			// Add the edge to the to slice of the from node.
			if (n[from] == null) {
				n[from] = new Node();
			}
			n[from].to = append(n[from].to, to);

			// Add the edge to the to slice of the to node.
			if (n[to] == null) {
				n[to] = new Node();
			}
			n[to].to = append(n[to].to, from);
		}

		// Print the number of neighbors for each node.
		for (int i = 0; i < N; i++) {
			// Print the number of neighbors of the current node.
			out(n[i].to.length);
		}
	}
}

// 