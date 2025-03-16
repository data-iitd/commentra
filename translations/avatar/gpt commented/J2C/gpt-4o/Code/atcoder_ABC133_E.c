#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a node in the tree
typedef struct Node {
    long pattern; // Variable to store the pattern value
    int index; // Index of the node
    int* children; // Array of child nodes
    int child_count; // Number of children
    int parent; // Parent index, -1 indicates no parent
} Node;

// Function to create a new node
Node* createNode(int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->pattern = 0;
    node->index = index;
    node->children = NULL;
    node->child_count = 0;
    node->parent = -1;
    return node;
}

// Function to set the parent of the node and calculate the pattern
void setParent(Node* node, int K, int parent, int use, Node** nodes) {
    node->pattern = K - use; // Calculate the pattern based on K and used count
    node->parent = parent; // Set the parent index
    int count = 1; // Initialize count of used nodes

    // If the node has a parent, increment the count
    if (parent != -1) {
        count++;
    }

    // Recursively set the parent for each child node
    for (int i = 0; i < node->child_count; i++) {
        int child_index = node->children[i];
        if (child_index == parent) { // Skip the parent node
            continue;
        }
        setParent(nodes[child_index], K, node->index, count, nodes); // Recursive call for child
        count++; // Increment count for each child processed
    }
}

// Main logic to solve the problem
void solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read the number of nodes and the value of K
    Node** nodes = (Node**)malloc(N * sizeof(Node*)); // Array to hold all nodes

    // Initialize nodes
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i); // Create a new node for each index
        nodes[i]->children = (int*)malloc((N - 1) * sizeof(int)); // Allocate space for children
        nodes[i]->child_count = 0; // Initialize child count
    }

    // Read edges and build the tree structure
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read first node of the edge
        a--; b--; // Convert to zero-based index
        nodes[a]->children[nodes[a]->child_count++] = b; // Add b as a child of a
        nodes[b]->children[nodes[b]->child_count++] = a; // Add a as a child of b (undirected tree)
    }

    // Set the parent for the root node (node 0)
    setParent(nodes[0], K, -1, 0, nodes);

    long patterns = 1; // Variable to store the product of patterns

    // Calculate the product of all node patterns
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i]->pattern) % MOD; // Update patterns with modulo
    }

    // Output the final result
    printf("%ld\n", patterns);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(nodes[i]->children); // Free children array
        free(nodes[i]); // Free node
    }
    free(nodes); // Free nodes array
}

// Main method to execute the program
int main() {
    solve(); // Call the solve function to execute the logic
    return 0;
}

// <END-OF-CODE>
