#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent each node in the graph
typedef struct Node {
    int val;  // Value of the node
    bool color;  // Color of the node (True/False)
    int *a;  // Adjacency list to store connected nodes and weights
    int a_size;  // Size of the adjacency list
} Node;

// Read the number of nodes from input
int n;
scanf("%d", &n);

// Initialize nodes and store them in a list
Node *nodes = malloc(n * sizeof(Node));
for (int i = 0; i < n; i++) {
    nodes[i].val = i + 1;  // Set the value of the node
    nodes[i].color = false;  // Set the color of the node to False
    nodes[i].a = NULL;  // Initialize the adjacency list
    nodes[i].a_size = 0;  // Initialize the size of the adjacency list
}

// Read edges and construct the graph
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    Node *node1 = &nodes[u - 1];  // Get the first node (adjusting for 0-indexing)
    Node *node2 = &nodes[v - 1];  // Get the second node (adjusting for 0-indexing)
    // Add the edge to both nodes' adjacency lists
    node1->a = realloc(node1->a, (node1->a_size + 1) * sizeof(int));
    node1->a[node1->a_size] = v;
    node1->a_size++;
    node2->a = realloc(node2->a, (node2->a_size + 1) * sizeof(int));
    node2->a[node2->a_size] = u;
    node2->a_size++;
}

// Set the root node and initialize its color
Node *root = &nodes[0];
root->color = true;  // Color the root node as True
int *nodeSet = malloc(n * sizeof(int));  // Set to keep track of visited nodes

// Define a recursive function to traverse the graph
void traverse(Node *node, int distance) {
    // If the node has already been visited, return
    if (nodeSet[node->val - 1]) {
        return;
    } else {
        nodeSet[node->val - 1] = true;  // Mark the node as visited
    }

    // Iterate through each adjacent node
    for (int i = 0; i < node->a_size; i++) {
        Node *adjNode = &nodes[node->a[i] - 1];  // Get the adjacent node
        int dis = node->a[i];  // Get the distance (weight) to the adjacent node
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
    Node *node = &nodes[i];
    if (node->color) {
        printf("1\n");  // Print 1 for True color
    } else {
        printf("0\n");  // Print 0 for False color
    }
}

