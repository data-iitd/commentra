#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Inner class to represent a node in the tree
typedef struct Node { 
    long pattern; // Variable to store the pattern value
    int index; // Index of the node
    int *children; // List of child nodes
    int parent; // Parent index, -1 indicates no parent
} Node; 

// Main logic to solve the problem
void solve() { 
    int N, K; // Number of nodes and value of K
    scanf("%d %d", &N, &K); // Read the number of nodes and value of K
    Node *nodes = (Node *)malloc(N * sizeof(Node)); // Array to hold all nodes

    // Initialize nodes
    for (int i = 0; i < N; i++) { 
        nodes[i].index = i; // Set the index of the node
        nodes[i].children = (int *)malloc(N * sizeof(int)); // Allocate memory for children
        nodes[i].parent = -1; // Set the parent index to -1
    } 

    // Read edges and build the tree structure
    for (int i = 0; i < N - 1; i++) { 
        int a, b; // Read first and second node of the edge
        scanf("%d %d", &a, &b); 
        nodes[a].children[i] = b; // Add b as a child of a
        nodes[b].children[i] = a; // Add a as a child of b (undirected tree)
    } 

    // Set the parent for the root node (node 0)
    nodes[0].parent = -1; 

    long patterns = 1; // Variable to store the product of patterns

    // Calculate the product of all node patterns
    for (int i = 0; i < N; i++) { 
        patterns = (patterns * nodes[i].pattern) % 1000000007; // Update patterns with modulo
    } 

    // Output the final result
    printf("%ld\n", patterns); 

    // Free memory
    for (int i = 0; i < N; i++) { 
        free(nodes[i].children); 
    } 
    free(nodes); 
} 

// Main method to execute the program
int main() { 
    solve(); // Call the solve method to execute the logic
    return 0; 
} 

