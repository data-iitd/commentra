#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000 // Define a maximum number of nodes

// Node structure to represent a graph node with a list of connected nodes
typedef struct Node {
    int *to; // Array to hold indices of connected nodes
    int degree; // To keep track of the number of connections
} Node;

// Function to read an integer from standard input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

<<<<<<< HEAD
// Function to initialize a node
void initNode(Node *node) {
    node->to = (int *)malloc(MAX_NODES * sizeof(int)); // Allocate memory for connections
    node->degree = 0; // Initialize degree to 0
}

// Function to free the memory allocated for a node
void freeNode(Node *node) {
    free(node->to); // Free the connections array
}

int main() {
    int N = getInt(); // Read the number of nodes
    int M = getInt(); // Read the number of edges

    // Create an array of Node structures to represent the graph
    Node *nodes = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        initNode(&nodes[i]); // Initialize each node
=======
// Function to print output to the console
void out(int x) {
    printf("%d\n", x);
}

int main() {
    int N, M;
    // Read the number of nodes (N) and edges (M) from input
    N = getInt();
    M = getInt();

    // Create an array of Node structures to represent the graph
    Node n[MAX_NODES];
    for (int i = 0; i < N; i++) {
        n[i].to = (int *)malloc(MAX_NODES * sizeof(int)); // Allocate memory for connections
        n[i].degree = 0; // Initialize degree
>>>>>>> 98c87cb78a (data updated)
    }

    // Read M edges and populate the graph
    for (int i = 0; i < M; i++) {
<<<<<<< HEAD
        int from = getInt() - 1; // Read the edge start (0-indexed)
        int to = getInt() - 1;   // Read the edge end (0-indexed)

        // Add the connection from 'from' to 'to'
        nodes[from].to[nodes[from].degree++] = to; 
        // Add the connection from 'to' to 'from' (undirected graph)
        nodes[to].to[nodes[to].degree++] = from; 
=======
        int from = getInt() - 1; // Read the edge endpoint (0-indexed)
        int to = getInt() - 1; // Read the edge endpoint (0-indexed)
        
        n[from].to[n[from].degree++] = to; // Add the connection from 'from' to 'to'
        n[to].to[n[to].degree++] = from; // Add the connection from 'to' to 'from' (undirected graph)
>>>>>>> 98c87cb78a (data updated)
    }

    // Output the degree (number of connections) of each node
    for (int i = 0; i < N; i++) {
<<<<<<< HEAD
        printf("%d\n", nodes[i].degree); // Print the number of connections for node i
=======
        out(n[i].degree); // Print the number of connections for node i
>>>>>>> 98c87cb78a (data updated)
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
<<<<<<< HEAD
        freeNode(&nodes[i]); // Free each node's connections
    }
    free(nodes); // Free the nodes array
=======
        free(n[i].to);
    }
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

// <END-OF-CODE>
