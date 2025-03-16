
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    long pattern; // Stores the pattern for the node
    int index; // Index of the node in the tree
    int parent; // Index of the parent node, initialized to -1 for root
    int children; // List of children nodes
} Node;

// Method to solve the problem
void solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read number of nodes and parameter K
    Node* nodes = (Node*) malloc(N * sizeof(Node)); // Initialize array of nodes
    for (int i = 0; i < N; i++) {
        nodes[i].index = i; // Initialize each node
        nodes[i].parent = -1; // Initialize parent to -1 for root
        nodes[i].children = 0; // Initialize children to 0
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read edge node a and b
        nodes[a - 1].children++; // Increment children for a
        nodes[b - 1].children++; // Increment children for b
        nodes[a - 1].children = nodes[a - 1].children + 1; // Add b as a child of a
        nodes[b - 1].children = nodes[b - 1].children + 1; // Add a as a child of b
    }
    nodes[0].parent = -1; // Set parent for the root node
    nodes[0].pattern = K; // Set pattern for the root node
    for (int i = 0; i < N; i++) {
        if (nodes[i].children > 0) { // If the node has children
            nodes[i].pattern = K - nodes[i].children; // Set pattern for the node
        }
    }
    long patterns = 1; // Initialize patterns variable
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1000000007; // Calculate total patterns
    }
    printf("%ld\n", patterns); // Print the result
}

// Main method to execute the program
int main(int argc, char** argv) {
    solve();
    return 0;
}

