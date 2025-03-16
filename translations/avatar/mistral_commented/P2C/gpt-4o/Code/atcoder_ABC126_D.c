#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

// Define a Node structure
typedef struct Node {
    int val;
    bool color;
    struct Node** adjacencies;
    int* weights;
    int adj_count;
} Node;

// Global variables
Node nodes[MAX_NODES];
bool visited[MAX_NODES];

// Function to initialize a node
void init_node(Node* node, int value) {
    node->val = value;
    node->color = true; // Set default color
    node->adj_count = 0;
    node->adjacencies = malloc(sizeof(Node*) * (MAX_NODES - 1)); // Allocate memory for adjacencies
    node->weights = malloc(sizeof(int) * (MAX_NODES - 1)); // Allocate memory for weights
}

// Function to traverse the graph and color nodes based on their distance from the root
void traverse(Node* node, int distance) {
    // Check if node has already been visited
    if (visited[node->val]) {
        return;
    }
    // Mark node as visited
    visited[node->val] = true;

    // Color node based on its distance from the root
    for (int i = 0; i < node->adj_count; i++) {
        Node* adj_node = node->adjacencies[i];
        int adj_distance = node->weights[i];
        if ((distance + adj_distance) % 2 == 0) {
            adj_node->color = node->color;
        } else {
            adj_node->color = !node->color;
        }
        traverse(adj_node, distance + adj_distance);
    }
}

int main() {
    // Set the maximum recursion depth (not applicable in C like in Python)
    
    // Read input and initialize nodes
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        init_node(&nodes[i], i);
    }

    // Read edges and add adjacencies to nodes
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; // Convert to 0-based index
        v--; // Convert to 0-based index
        nodes[u].adjacencies[nodes[u].adj_count] = &nodes[v];
        nodes[u].weights[nodes[u].adj_count] = w;
        nodes[u].adj_count++;
        nodes[v].adjacencies[nodes[v].adj_count] = &nodes[u];
        nodes[v].weights[nodes[v].adj_count] = w;
        nodes[v].adj_count++;
    }

    // Set the root node and color it
    Node* root = &nodes[0];
    root->color = true;

    // Traverse the graph starting from the root
    traverse(root, 0);

    // Print the color of each node
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i].color ? 1 : 0);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(nodes[i].adjacencies);
        free(nodes[i].weights);
    }

    return 0;
}

// <END-OF-CODE>
