#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// Create a new scanner to read input from standard input.
FILE *sc = stdin;

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	char *line = NULL;
	size_t size = 0;
	int i;
	if (getline(&line, &size, sc) == -1) {
		panic("Error reading input");
	}
	i = atoi(line);
	free(line);
	return i;
}

// getString reads a string from standard input and returns it.
char *getString() {
	char *line = NULL;
	size_t size = 0;
	if (getline(&line, &size, sc) == -1) {
		panic("Error reading input");
	}
	return line;
}

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
	int to_len;
} Node;

int main() {
	// Set the scanner to split input by whitespace
	// sc.Split(bufio.ScanWords)

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt();
	int M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(N * sizeof(Node));

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1; // Read the edge endpoints (0-indexed)
		int to = getInt() - 1;
		n[from].to = realloc(n[from].to, (n[from].to_len + 1) * sizeof(int));
		n[from].to[n[from].to_len] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, (n[to].to_len + 1) * sizeof(int));
		n[to].to[n[to].to_len] = from; // Add the connection from 'to' to 'from' (undirected graph)
		n[from].to_len++;
		n[to].to_len++;
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to_len); // Print the number of connections for node i
	}

	// Free the memory allocated for the graph
	for (int i = 0; i < N; i++) {
		free(n[i].to);
	}
	free(n);

	return 0;
}

