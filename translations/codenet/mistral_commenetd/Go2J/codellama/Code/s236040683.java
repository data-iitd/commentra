
// Package main is the entry point of the program.
package main

import java.util.Scanner; // We use Scanner for reading input.

// out is a custom function for printing output.
void out(Object... x) {
	System.out.println(x);
}

// sc is a buffer scanner for reading input.
Scanner sc = new Scanner(System.in);

// getInt reads and converts an integer from the input.
int getInt() {
	return sc.nextInt();
}

// getString reads and returns a string from the input.
String getString() {
	return sc.next();
}

// Node is a custom data structure for representing a node in the graph.
class Node {
	int[] to;

	Node(int[] to) {
		this.to = to;
	}
}

// main is the entry point of the program.
public static void main(String[] args) {
	// Set up the scanner to read words instead of lines.
	sc.useDelimiter("\\s+");

	// Read the number of nodes N and edges M from the input.
	int N = getInt();
	int M = getInt();

	// Create a slice n of size N to store the nodes.
	Node[] n = new Node[N];

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for (int i = 0; i < M; i++) {
		// Read the from and to nodes from the input.
		int from = getInt() - 1;
		int to = getInt() - 1;

		// Add the edge to the to slice of the from node.
		n[from].to = append(n[from].to, to);

		// Add the edge to the to slice of the to node.
		n[to].to = append(n[to].to, from);
	}

	// Print the number of neighbors for each node.
	for (int i = 0; i < N; i++) {
		// Print the number of neighbors of the current node.
		out(n[i].to.length);
	}
}

// 