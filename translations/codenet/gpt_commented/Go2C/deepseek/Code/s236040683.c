#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from standard input
char* getString() {
    char *str = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string
    scanf("%s", str);
    return str;
}

// Structure to represent a graph node with a pointer to the next node
typedef struct Node {
    int *to; // Pointer to an array of connected nodes
    int degree; // Degree of the node
} Node;

int main() {
    // Read the number of nodes (N) and edges (M) from input
    int N = getInt();
    int M = getInt();

    // Create an array of Node structures to represent the graph
    Node *n = (Node*)malloc(N * sizeof(Node));

    // Initialize the degree of each node to 0
    for (int i = 0; i < N; i++) {
        n[i].to = (int*)malloc(N * sizeof(int)); // Allocate memory for the connections array
        n[i].degree = 0; // Initialize degree to 0
    }

    // Read M edges and populate the graph
    for (int i = 0; i < M; i++) {
        int from = getInt() - 1; // Read the edge endpoints (0-indexed)
        int to = getInt() - 1; // Read the edge endpoints (0-indexed)
        n[from].to[n[from].degree++] = to; // Add the connection from 'from' to 'to'
        n[to].to[n[to].degree++] = from; // Add the connection from 'to' to 'from' (undirected graph)
    }

    // Output the degree (number of connections) of each node
    for (int i = 0; i < N; i++) {
        printf("%d\n", n[i].degree); // Print the number of connections for node i
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(n[i].to); // Free the connections array
    }
    free(n); // Free the array of nodes

    return 0;
}
