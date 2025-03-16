
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10000

// Define the Node struct to represent each node in the graph
typedef struct Node {
    int val;
    bool color;
    int a[MAX_NODES];
    int a_size;
} Node;

// Read the number of nodes in the graph
int n;
scanf("%d", &n);

// Create a list to store all nodes
Node nodes[MAX_NODES];
for (int i = 0; i < n; i++) {
    nodes[i].val = i + 1;
    nodes[i].a_size = 0;
}

// Read each edge in the graph and establish connections between nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    nodes[u - 1].a[nodes[u - 1].a_size++] = v - 1;
    nodes[v - 1].a[nodes[v - 1].a_size++] = u - 1;
}

// Set the root node to the first node in the list
Node *root = &nodes[0];

// Set the color of the root node to True
root->color = true;

// Initialize a set to keep track of visited nodes
bool nodeSet[MAX_NODES];
for (int i = 0; i < n; i++) {
    nodeSet[i] = false;
}

// Define the traverse function to recursively traverse the graph
void traverse(Node *node, int distance) {
    if (nodeSet[node->val - 1]) {
        return;
    } else {
        nodeSet[node->val - 1] = true;
    }
    for (int i = 0; i < node->a_size; i++) {
        Node *adjNode = &nodes[node->a[i]];
        int dis = adjNode->val - node->val;
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
    if (nodes[i].color) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

