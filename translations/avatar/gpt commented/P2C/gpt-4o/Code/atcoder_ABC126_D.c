#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Define a structure to represent each node in the graph
typedef struct Node {
    int val; // Value of the node
    int color; // Color of the node (0/1)
    struct Node** a; // Adjacency list to store connected nodes
    int* weights; // Weights of the edges
    int degree; // Number of edges
} Node;

Node nodes[MAX_NODES]; // Array to store nodes
int visited[MAX_NODES]; // Array to keep track of visited nodes

// Function to create a new node
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = 0;
    newNode->color = -1; // Uninitialized color
    newNode->a = (Node**)malloc(sizeof(Node*) * MAX_NODES);
    newNode->weights = (int*)malloc(sizeof(int) * MAX_NODES);
    newNode->degree = 0;
    return newNode;
}

// Recursive function to traverse the graph
void traverse(Node* node, int distance) {
    // If the node has already been visited, return
    if (visited[node->val]) {
        return;
    }
    visited[node->val] = 1; // Mark the node as visited

    // Iterate through each adjacent node
    for (int i = 0; i < node->degree; i++) {
        Node* adjNode = node->a[i]; // Get the adjacent node
        int dis = node->weights[i]; // Get the distance (weight) to the adjacent node
        // Determine the color of the adjacent node based on the distance
        if ((distance + dis) % 2 == 0) {
            adjNode->color = node->color; // Same color as current node
        } else {
            adjNode->color = !node->color; // Opposite color to current node
        }
        // Recursively traverse to the adjacent node
        traverse(adjNode, distance + dis);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize nodes
    for (int i = 0; i < n; i++) {
        nodes[i] = *createNode();
        nodes[i].val = i; // Set the value of the node
    }

    // Read edges and construct the graph
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; // Adjust for 0-indexing
        v--; // Adjust for 0-indexing

        // Add the edge to both nodes' adjacency lists
        nodes[u].a[nodes[u].degree] = &nodes[v];
        nodes[u].weights[nodes[u].degree] = w;
        nodes[u].degree++;

        nodes[v].a[nodes[v].degree] = &nodes[u];
        nodes[v].weights[nodes[v].degree] = w;
        nodes[v].degree++;
    }

    // Set the root node and initialize its color
    Node* root = &nodes[0];
    root->color = 1; // Color the root node as 1 (True)

    // Start the traversal from the root node with an initial distance of 0
    traverse(root, 0);

    // Output the color of each node
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i].color); // Print the color of each node
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(nodes[i].a);
        free(nodes[i].weights);
    }

    return 0;
}

// <END-OF-CODE>
