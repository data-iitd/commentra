

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    long pattern; // Stores the pattern for the node
    int index; // Index of the node in the tree
    int *children; // Array of children nodes
    int parent; // Index of the parent node, initialized to -1 for root
    int children_count; // Number of children nodes
} Node;

// Method to solve the problem
void solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read number of nodes and parameter K
    Node *nodes = (Node*)malloc(sizeof(Node) * N); // Initialize array of nodes
    for (int i = 0; i < N; i++) {
        nodes[i].index = i; // Initialize each node
        nodes[i].children = (int*)malloc(sizeof(int) * (N - 1)); // Initialize array of children nodes
        nodes[i].children_count = 0; // Initialize count of children nodes
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read edge node a and b
        nodes[a - 1].children[nodes[a - 1].children_count] = b - 1; // Add b as a child of a
        nodes[b - 1].children[nodes[b - 1].children_count] = a - 1; // Add a as a child of b
        nodes[a - 1].children_count++; // Increment count of children for a
        nodes[b - 1].children_count++; // Increment count of children for b
    }
    nodes[0].pattern = K - 1; // Set pattern for the root node
    nodes[0].parent = -1; // Set parent for the root node
    long patterns = 1; // Initialize patterns variable
    for (int i = 0; i < N; i++) {
        int count = 1; // Initialize count of children
        if (nodes[i].parent!= -1) {
            count++; // Increment count if the node has a parent
        }
        for (int j = 0; j < nodes[i].children_count; j++) { // Iterate through children
            int child = nodes[i].children[j];
            if (child == nodes[i].parent) {
                continue; // Skip the current parent to avoid recursion loop
            }
            nodes[child].pattern = K - count; // Set pattern for the child node
            nodes[child].parent = nodes[i].index; // Set parent for the child node
            count++; // Increment count for the next child
        }
        patterns = (patterns * nodes[i].pattern) % 100000007; // Calculate total patterns
    }
    printf("%ld\n", patterns); // Print the result
}

int main() {
    solve(); // Execute the program
    return 0;
}

