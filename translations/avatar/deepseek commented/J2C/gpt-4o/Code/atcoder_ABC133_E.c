#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    long pattern; // Stores the pattern for the node
    int index; // Index of the node in the tree
    int* children; // List of children nodes
    int children_count; // Number of children
    int parent; // Index of the parent node, initialized to -1 for root
} Node;

// Function to create a new node
Node* createNode(int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->pattern = 0;
    node->index = index;
    node->children = (int*)malloc(sizeof(int) * 100); // Assuming a maximum of 100 children
    node->children_count = 0;
    node->parent = -1;
    return node;
}

// Function to set the parent of the node recursively
void setParent(Node* node, int K, int parent, int use, Node** nodes) {
    node->pattern = K - use; // Set the pattern for the node
    node->parent = parent; // Set the parent index
    int count = 1; // Initialize count of children
    if (parent != -1) {
        count++; // Increment count if the node has a parent
    }
    for (int i = 0; i < node->children_count; i++) { // Iterate through children
        int child_index = node->children[i];
        if (child_index == node->parent) {
            continue; // Skip the current parent to avoid recursion loop
        }
        setParent(nodes[child_index], K, node->index, count, nodes); // Recursively set parent for children
        count++; // Increment count for the next child
    }
}

// Function to solve the problem
void solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read number of nodes and parameter K
    Node** nodes = (Node**)malloc(sizeof(Node*) * N); // Initialize array of nodes
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i); // Initialize each node
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read edge node a and b
        a--; b--; // Convert to zero-based index
        nodes[a]->children[nodes[a]->children_count++] = b; // Add b as a child of a
        nodes[b]->children[nodes[b]->children_count++] = a; // Add a as a child of b
    }
    nodes[0]->setParent(K, -1, 0, nodes); // Set parent for the root node
    long patterns = 1; // Initialize patterns variable
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i]->pattern) % MOD; // Calculate total patterns
    }
    printf("%ld\n", patterns); // Print the result

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(nodes[i]->children);
        free(nodes[i]);
    }
    free(nodes);
}

// Main function to execute the program
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
