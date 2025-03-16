
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent each node in the graph
typedef struct Node {
    int val;  // Value of the node
    int color;  // Color of the node (1/0)
    struct Node *a;  // Adjacency list to store connected nodes and weights
} Node;

// Define a function to traverse the graph recursively
void traverse(Node *node, int distance) {
    // If the node has already been visited, return
    if (node->color!= 0) {
        return;
    } else {
        node->color = 1;  // Mark the node as visited
    }

    // Iterate through each adjacent node
    Node *adjNode;
    int dis;
    for (int i = 0; i < node->a->val; i++) {
        adjNode = node->a->a[i].node;  // Get the adjacent node
        dis = node->a->a[i].weight;  // Get the distance (weight) to the adjacent node
        // Determine the color of the adjacent node based on the distance
        if ((distance + dis) % 2 == 0) {
            adjNode->color = node->color;  // Same color as root
        } else {
            adjNode->color = 3 - node->color;  // Opposite color to root
        }
        // Recursively traverse to the adjacent node
        traverse(adjNode, distance + dis);
    }
}

int main() {
    int n;  // Number of nodes
    scanf("%d", &n);

    // Initialize nodes and store them in an array
    Node *nodes = (Node *)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].val = i + 1;  // Set the value of the node
        nodes[i].color = 0;  // Set the color of the node as unvisited
        nodes[i].a = (Node *)malloc(sizeof(Node));  // Allocate memory for the adjacency list
        nodes[i].a->val = 0;  // Initialize the adjacency list with 0 edges
    }

    // Read edges and construct the graph
    int u, v, w;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        nodes[u - 1].a->val++;  // Increment the number of edges for the first node
        nodes[u - 1].a->a = (struct { Node *node; int weight; })realloc(nodes[u - 1].a->a, nodes[u - 1].a->val * sizeof(struct { Node *node; int weight; }));
        nodes[u - 1].a->a[nodes[u - 1].a->val - 1].node = &nodes[v - 1];  // Add the adjacent node and weight to the first node's adjacency list
        nodes[u - 1].a->a[nodes[u - 1].a->val - 1].weight = w;
        nodes[v - 1].a->val++;  // Increment the number of edges for the second node
        nodes[v - 1].a->a = (struct { Node *node; int weight; })realloc(nodes[v - 1].a->a, nodes[v - 1].a->val * sizeof(struct { Node *node; int weight; }));
        nodes[v - 1].a->a[nodes[v - 1].a->val - 1].node = &nodes[u - 1];  // Add the adjacent node and weight to the second node's adjacency list
        nodes[v - 1].a->a[nodes[v - 1].a->val - 1].weight = w;
    }

    // Set the root node and initialize its color
    Node *root = &nodes[0];
    root->color = 1;  // Color the root node as True

    // Start the traversal from the root node with an initial distance of 0
    traverse(root, 0);

    // Output the color of each node
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i].color);  // Print the color of each node
    }

    return 0;
}
