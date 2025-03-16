#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Define a structure to represent each node in the graph
typedef struct Node {
    int val;  // Value of the node
    int color;  // Color of the node (True/False)
    struct Node** adj;  // Adjacency list to store connected nodes and weights
    int adj_size;  // Size of the adjacency list
} Node;

// Read the number of nodes from input
int n;
scanf("%d", &n);
Node* nodes[MAX_NODES];

// Initialize nodes and store them in an array
for (int i = 0; i < n; i++) {
    nodes[i] = (Node*)malloc(sizeof(Node));
    nodes[i]->val = i;
    nodes[i]->color = -1;
    nodes[i]->adj = (Node**)malloc(0);
    nodes[i]->adj_size = 0;
}

// Read edges and construct the graph
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    // Adjust for 0-indexing
    u--;
    v--;
    // Resize adjacency lists
    nodes[u]->adj = (Node**)realloc(nodes[u]->adj, (nodes[u]->adj_size + 1) * sizeof(Node*));
    nodes[v]->adj = (Node**)realloc(nodes[v]->adj, (nodes[v]->adj_size + 1) * sizeof(Node*));
    // Add the edge to both nodes' adjacency lists
    nodes[u]->adj[nodes[u]->adj_size] = nodes[v];
    nodes[v]->adj[nodes[v]->adj_size] = nodes[u];
    nodes[u]->adj_size++;
    nodes[v]->adj_size++;
}

// Set the root node and initialize its color
Node* root = nodes[0];
root->color = 1;  // Color the root node as True
int visited[MAX_NODES] = {0};  // Array to keep track of visited nodes

// Define a recursive function to traverse the graph
void traverse(Node* node, int distance) {
    // If the node has already been visited, return
    if (visited[node->val]) {
        return;
    }
    visited[node->val] = 1;  // Mark the node as visited

    // Iterate through each adjacent node
    for (int i = 0; i < node->adj_size; i++) {
        Node* adjNode = node->adj[i];
        int dis = 1;  // Get the distance (weight) to the adjacent node
        // Determine the color of the adjacent node based on the distance
        if ((distance + dis) % 2 == 0) {
            adjNode->color = root->color;  // Same color as root
        } else {
            adjNode->color = !root->color;  // Opposite color to root
        }
        // Recursively traverse to the adjacent node
        traverse(adjNode, distance + dis);
    }
}

// Start the traversal from the root node with an initial distance of 0
traverse(root, 0);

// Output the color of each node
for (int i = 0; i < n; i++) {
    printf("%d\n", nodes[i]->color);
    free(nodes[i]->adj);  // Free the adjacency list
    free(nodes[i]);  // Free the node
}

