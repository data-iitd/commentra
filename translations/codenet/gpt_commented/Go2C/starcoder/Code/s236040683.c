

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1, to = getInt() - 1; // Read the edge endpoints (0-indexed)
		n[from].to = realloc(n[from].to, sizeof(int) * (1 + (n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0)));
		n[from].to[n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, sizeof(int) * (1 + (n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0)));
		n[to].to[n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0] = from; // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to? (int)sizeof(n[i].to) / sizeof(int) : 0); // Print the number of connections for node i
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1, to = getInt() - 1; // Read the edge endpoints (0-indexed)
		n[from].to = realloc(n[from].to, sizeof(int) * (1 + (n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0)));
		n[from].to[n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, sizeof(int) * (1 + (n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0)));
		n[to].to[n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0] = from; // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to? (int)sizeof(n[i].to) / sizeof(int) : 0); // Print the number of connections for node i
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1, to = getInt() - 1; // Read the edge endpoints (0-indexed)
		n[from].to = realloc(n[from].to, sizeof(int) * (1 + (n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0)));
		n[from].to[n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, sizeof(int) * (1 + (n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0)));
		n[to].to[n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0] = from; // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to? (int)sizeof(n[i].to) / sizeof(int) : 0); // Print the number of connections for node i
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1, to = getInt() - 1; // Read the edge endpoints (0-indexed)
		n[from].to = realloc(n[from].to, sizeof(int) * (1 + (n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0)));
		n[from].to[n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, sizeof(int) * (1 + (n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0)));
		n[to].to[n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0] = from; // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to? (int)sizeof(n[i].to) / sizeof(int) : 0); // Print the number of connections for node i
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph
	for (int i = 0; i < M; i++) {
		int from = getInt() - 1, to = getInt() - 1; // Read the edge endpoints (0-indexed)
		n[from].to = realloc(n[from].to, sizeof(int) * (1 + (n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0)));
		n[from].to[n[from].to? (int)sizeof(n[from].to) / sizeof(int) : 0] = to; // Add the connection from 'from' to 'to'
		n[to].to = realloc(n[to].to, sizeof(int) * (1 + (n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0)));
		n[to].to[n[to].to? (int)sizeof(n[to].to) / sizeof(int) : 0] = from; // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for (int i = 0; i < N; i++) {
		out(n[i].to? (int)sizeof(n[i].to) / sizeof(int) : 0); // Print the number of connections for node i
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a graph node with a slice of connected nodes.
typedef struct {
	int *to; // Slice to hold indices of connected nodes
} Node;

// out is a helper function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a string from standard input and returns it.
char* getString() {
	char *str = malloc(1000000);
	scanf("%s", str);
	return str;
}

// main is the entry point of the program.
int main(int argc, char *argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);

	// Read the number of nodes (N) and edges (M) from input
	int N = getInt(), M = getInt();
	// Create a slice of Node structures to represent the graph
	Node *n = malloc(sizeof(Node) * N);

	// Read M edges and populate the graph