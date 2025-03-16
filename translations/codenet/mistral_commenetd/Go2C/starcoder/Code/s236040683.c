#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node is a custom data structure for representing a node in the graph.
typedef struct Node {
	int to[100000];
} Node;

// out is a custom function for printing output.
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Read the number of nodes N and edges M from the input.
	int N, M;
	scanf("%d %d", &N, &M);

	// Create a slice n of size N to store the nodes.
	Node n[N];

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for (int i = 0; i < M; i++) {
		// Read the from and to nodes from the input.
		int from, to;
		scanf("%d %d", &from, &to);

		// Add the edge to the to slice of the from node.
		n[from].to[n[from].to[0]] = to;
		n[from].to[0]++;

		// Add the edge to the to slice of the to node.
		n[to].to[n[to].to[0]] = from;
		n[to].to[0]++;
	}

	// Print the number of neighbors for each node.
	for (int i = 0; i < N; i++) {
		// Print the number of neighbors of the current node.
		out("%d\n", n[i].to[0]);
	}
}

// 