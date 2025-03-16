
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node struct
typedef struct Node {
    int val;
    bool color;
    struct Node** adjacencies;
} Node;

// Initialize the root node
Node* root = NULL;

// Read input and initialize nodes
int n = 0;
scanf("%d", &n);
Node** nodes = (Node**)malloc(n * sizeof(Node*));
for (int i = 0; i < n; i++) {
    nodes[i] = (Node*)malloc(sizeof(Node));
    nodes[i]->val = i + 1;
    nodes[i]->color = false;
    nodes[i]->adjacencies = (Node**)malloc(n * sizeof(Node*));
}

// Read edges and add adjacencies to nodes
for (int i = 0; i < n - 1; i++) {
    int u = 0, v = 0, w = 0;
    scanf("%d %d %d", &u, &v, &w);
    Node* node_u = nodes[u - 1];
    Node* node_v = nodes[v - 1];
    node_u->adjacencies[i] = node_v;
    node_v->adjacencies[i] = node_u;
}

// Set the root node and color it
root = nodes[0];
root->color = true;

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node* node, int distance) {
    // Check if node has already been visited
    if (node->color) {
        return;
    }
    // Mark node as visited
    node->color = true;
    // Color node based on its distance from the root
    for (int i = 0; i < n; i++) {
        Node* adj = node->adjacencies[i];
        if ((distance + adj->val) % 2 == 0) {
            adj->color = root->color;
        } else {
            adj->color = !root->color;
        }
        traverse(adj, distance + adj->val);
    }
}

// Traverse the graph starting from the root
traverse(root, 0);

// Print the color of each node
for (int i = 0; i < n; i++) {
    if (nodes[i]->color) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

