#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    long pattern; // Pattern to store the result of the subtree rooted at this node
    int index; // Index of the node in the array
    struct Node** children; // Array to store pointers to children nodes
    int parent; // Index of the parent node
    int child_count; // Number of children

} Node;

void setParent(Node* node, int K, int parent, int use, Node* nodes) {
    node->pattern = K - use;
    node->parent = parent;
    int count = 1;

    if (parent != -1) {
        count++;
    }

    for (int i = 0; i < node->child_count; i++) {
        Node* child = node->children[i];
        if (child->index == parent) {
            continue; // Avoid self-loop
        }
        setParent(child, K, node->index, count, nodes); // Recursively set parent and calculate pattern for child
        count++;
    }
}

long solve() {
    int N, K;
    scanf("%d %d", &N, &K); // Read number of nodes and sum of edges' weights

    Node* nodes = (Node*)malloc(N * sizeof(Node)); // Allocate memory for nodes
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].pattern = 0;
        nodes[i].parent = -1;
        nodes[i].child_count = 0;
        nodes[i].children = (Node**)malloc((N - 1) * sizeof(Node*)); // Allocate memory for children
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        nodes[a].children[nodes[a].child_count++] = &nodes[b]; // Add child to node a
        nodes[b].children[nodes[b].child_count++] = &nodes[a]; // Add child to node b
    }

    nodes[0].setParent(K, -1, 0, nodes); // Set parent and calculate pattern for the root node
    long patterns = 1; // Initialize result variable

    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % MOD; // Calculate the pattern for the entire tree
    }

    for (int i = 0; i < N; i++) {
        free(nodes[i].children); // Free allocated memory for children
    }
    free(nodes); // Free allocated memory for nodes

    return patterns; // Return the result
}

int main() {
    long result = solve(); // Call the solve function
    printf("%ld\n", result); // Print the result
    return 0;
}

// <END-OF-CODE>
