#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Define the Node structure to represent each node in the graph
typedef struct Node {
    int val;
    int color;
    struct Node** adj;
    int adj_size;
} Node;

// Read the number of nodes in the graph
int n;
scanf("%d", &n);

// Create a list to store all nodes
Node* nodes[MAX_NODES];
for (int i = 0; i < n; i++) {
    nodes[i] = (Node*)malloc(sizeof(Node));
    nodes[i]->adj = (Node**)malloc(MAX_NODES * sizeof(Node*));
    nodes[i]->adj_size = 0;
}

// Read each edge in the graph and establish connections between nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    Node* node1 = nodes[u - 1];
    Node* node2 = nodes[v - 1];
    node1->adj[node1->adj_size++] = node2;
    node2->adj[node2->adj_size++] = node1;
    node1->val = u;
    node2->val = v;
}

// Set the root node to the first node in the list
Node* root = nodes[0];

// Set the color of the root node to True
root->color = 1;

// Initialize a set to keep track of visited nodes
int visited[MAX_NODES] = {0};

// Define the traverse function to recursively traverse the graph
void traverse(Node* node, int distance) {
    if (visited[node->val - 1]) {
        return;
    }
    visited[node->val - 1] = 1;
    for (int i = 0; i < node->adj_size; i++) {
        Node* adjNode = node->adj[i];
        int dis = 1; // Assuming each edge has a weight of 1 for simplicity
        if ((distance + dis) % 2 == 0) {
            adjNode->color = root->color;
        } else {
            adjNode->color = !root->color;
        }
        traverse(adjNode, distance + dis);
    }
}

// Call the traverse function starting from the root node with a distance of 0
traverse(root, 0);

// Print the color of each node
for (int i = 0; i < n; i++) {
    Node* node = nodes[i];
    printf("%d\n", node->color);
}

// Free allocated memory
for (int i = 0; i < n; i++) {
    free(nodes[i]->adj);
    free(nodes[i]);
}

