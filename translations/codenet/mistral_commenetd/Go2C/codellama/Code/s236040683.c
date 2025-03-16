
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node is a custom data structure for representing a node in the graph.
typedef struct {
	int *to;
	int to_size;
} Node;

// main is the entry point of the program.
int main() {
	// Set up the scanner to read words instead of lines.
	char *word;
	int word_size;

	// Read the number of nodes N and edges M from the input.
	int N, M;
	scanf("%d %d", &N, &M);

	// Create a slice n of size N to store the nodes.
	Node *n = malloc(N * sizeof(Node));

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for (int i = 0; i < M; i++) {
		// Read the from and to nodes from the input.
		int from, to;
		scanf("%d %d", &from, &to);

		// Add the edge to the to slice of the from node.
		n[from].to = realloc(n[from].to, (n[from].to_size + 1) * sizeof(int));
		n[from].to[n[from].to_size] = to;
		n[from].to_size++;

		// Add the edge to the to slice of the to node.
		n[to].to = realloc(n[to].to, (n[to].to_size + 1) * sizeof(int));
		n[to].to[n[to].to_size] = from;
		n[to].to_size++;
	}

	// Print the number of neighbors for each node.
	for (int i = 0; i < N; i++) {
		// Print the number of neighbors of the current node.
		printf("%d\n", n[i].to_size);
	}

	// Free the memory allocated for the nodes.
	for (int i = 0; i < N; i++) {
		free(n[i].to);
	}
	free(n);

	return 0;
}

