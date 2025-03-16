
#include <stdio.h>
#include <stdlib.h>

// Define a Node struct
typedef struct Node {
    int val;
    bool color;
    struct Node **adjacencies;
} Node;

// Read input and initialize nodes
int n;
scanf("%d", &n);
Node *nodes = (Node *)malloc(n * sizeof(Node));
for (int i = 0; i < n; i++) {
    nodes[i].val = i;
    nodes[i].color = false;
    nodes[i].adjacencies = (Node **)malloc(n * sizeof(Node *));
    for (int j = 0; j < n; j++) {
        nodes[i].adjacencies[j] = NULL;
    }
}

// Read edges and add adjacencies to nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    nodes[u - 1].adjacencies[v - 1] = &nodes[v - 1];
    nodes[v - 1].adjacencies[u - 1] = &nodes[u - 1];
}

// Set the root node and color it
Node *root = &nodes[0];
root->color = true;

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node *node, int distance) {
    // Check if node has already been visited
    if (node->color) {
        return;
    }
    // Mark node as visited
    node->color = true;
    // Color node based on its distance from the root
    for (int i = 0; i < n; i++) {
        if (nodes[i].adjacencies[node->val]!= NULL) {
            Node *adj_node = nodes[i].adjacencies[node->val];
            int adj_distance = nodes[i].adjacencies[node->val]->val;
            if ((distance + adj_distance) % 2 == 0) {
                adj_node->color = root->color;
            } else {
                adj_node->color =!root->color;
            }
            traverse(adj_node, distance + adj_distance);
        }
    }
}

// Traverse the graph starting from the root
traverse(root, 0);

// Print the color of each node
for (int i = 0; i < n; i++) {
    if (nodes[i].color) {
        printf("1 ");
    } else {
        printf("0 ");
    }
}

