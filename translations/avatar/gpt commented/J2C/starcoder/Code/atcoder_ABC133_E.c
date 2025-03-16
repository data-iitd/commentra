#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    long pattern; // Variable to store the pattern value
    int index; // Index of the node
    int parent; // Parent index, -1 indicates no parent
    int childrenCount; // Number of children
    int *children; // List of child nodes
} Node;

// Function to create a new node
Node* newNode(int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->pattern = 0;
    node->index = index;
    node->parent = -1;
    node->childrenCount = 0;
    node->children = NULL;
    return node;
}

// Function to set the parent of the node and calculate the pattern
void setParent(Node *node, int K, int parent, int use, Node **nodes) {
    node->pattern = K - use; // Calculate the pattern based on K and used count
    node->parent = parent; // Set the parent index
    int count = 1; // Initialize count of used nodes

    // If the node has a parent, increment the count
    if (parent!= -1) {
        count++;
    }

    // Recursively set the parent for each child node
    for (int i = 0; i < node->childrenCount; i++) {
        if (node->children[i] == node->parent) { // Skip the parent node
            continue;
        }
        setParent(nodes[node->children[i]], K, node->index, count, nodes); // Recursive call for child
        count++; // Increment count for each child processed
    }
}

// Main logic to solve the problem
void solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read the number of nodes and value of K
    Node **nodes = (Node**)malloc(sizeof(Node*) * N); // Array to hold all nodes

    // Initialize nodes
    for (int i = 0; i < N; i++) {
        nodes[i] = newNode(i); // Create a new node for each index
    }

    // Read edges and build the tree structure
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read first node of the edge
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        nodes[a]->childrenCount++; // Increment the number of children for a
        nodes[a]->children = (int*)realloc(nodes[a]->children, sizeof(int) * nodes[a]->childrenCount); // Reallocate memory for children
        nodes[a]->children[nodes[a]->childrenCount - 1] = b; // Add b as a child of a
        nodes[b]->childrenCount++; // Increment the number of children for b
        nodes[b]->children = (int*)realloc(nodes[b]->children, sizeof(int) * nodes[b]->childrenCount); // Reallocate memory for children
        nodes[b]->children[nodes[b]->childrenCount - 1] = a; // Add a as a child of b (undirected tree)
    }

    // Set the parent for the root node (node 0)
    setParent(nodes[0], K, -1, 0, nodes);

    long patterns = 1; // Variable to store the product of patterns

    // Calculate the product of all node patterns
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i]->pattern) % 1000000007; // Update patterns with modulo
    }

    // Output the final result
    printf("%ld\n", patterns);
}

// Main method to execute the program
int main(int argc, char const *argv[]) {
    solve(); // Call the solve method to execute the logic
    return 0;
}

