
#include <stdio.h>
#include <stdlib.h>

// out is a helper function to print output to the console.
void out(int x,...) {
    va_list args;
    va_start(args, x);
    vprintf(args);
    va_end(args);
    printf("\n");
}

// Create a new scanner to read input from standard input.
#define MAX_TOKEN_SIZE 100
char token[MAX_TOKEN_SIZE];

void scan(char *format) {
    fgets(token, MAX_TOKEN_SIZE, stdin);
    sscanf(token, format);
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
    int x;
    scan("%d", &x);
    return x;
}

// getString reads a string from standard input and returns it.
char *getString() {
    char *x = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
    scan("%s", x);
    return x;
}

// Node represents a graph node with a slice of connected nodes.
typedef struct {
    int *to; // Slice to hold indices of connected nodes
    int to_length;
} Node;

int main() {
    // Set the scanner to split input by whitespace
    setbuf(stdin, NULL);

    // Read the number of nodes (N) and edges (M) from input
    int N = getInt();
    int M = getInt();
    // Create a slice of Node structures to represent the graph
    Node *n = (Node *)malloc(N * sizeof(Node));

    // Read M edges and populate the graph
    for (int i = 0; i < M; i++) {
        int from = getInt() - 1; // Read the edge endpoints (0-indexed)
        int to = getInt() - 1;
        n[from].to = (int *)realloc(n[from].to, (n[from].to_length + 1) * sizeof(int));
        n[from].to[n[from].to_length] = to;
        n[from].to_length++;
        n[to].to = (int *)realloc(n[to].to, (n[to].to_length + 1) * sizeof(int));
        n[to].to[n[to].to_length] = from;
        n[to].to_length++;
    }

    // Output the degree (number of connections) of each node
    for (int i = 0; i < N; i++) {
        out("%d", n[i].to_length); // Print the number of connections for node i
    }

    return 0;
}
