#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

// Define the Node structure to represent each node in the graph
typedef struct Node {
    int val;
    bool color;
    struct Node* adj[MAX_NODES];
    int weights[MAX_NODES];
    int adjCount;
} Node;

// Global variables
Node nodes[MAX_NODES];
int n;
bool visited[MAX_NODES];

// Function to traverse the graph recursively
void traverse(Node* node, int distance) {
    int i;
    if (visited[node->val - 1]) {
        return;
    } else {
        visited[node->val - 1] = true;
    }
    
    for (i = 0; i < node->adjCount; i++) {
        Node* adjNode = node->adj[i];
        int dis = node->weights[i];
        if ((distance + dis) % 2 == 0) {
            adjNode->color = node->color;
        } else {
            adjNode->color = !node->color;
        }
        traverse(adjNode, distance + dis);
    }
}

int main() {
    // Read the number of nodes in the graph
    scanf("%d", &n);

    // Initialize nodes
    for (int i = 0; i < n; i++) {
        nodes[i].val = i + 1;
        nodes[i].adjCount = 0;
    }

    // Read each edge in the graph and establish connections between nodes
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        nodes[u - 1].adj[nodes[u - 1].adjCount] = &nodes[v - 1];
        nodes[u - 1].weights[nodes[u - 1].adjCount] = w;
        nodes[u - 1].adjCount++;
        
        nodes[v - 1].adj[nodes[v - 1].adjCount] = &nodes[u - 1];
        nodes[v - 1].weights[nodes[v - 1].adjCount] = w;
        nodes[v - 1].adjCount++;
    }

    // Set the root node to the first node in the list
    Node* root = &nodes[0];

    // Set the color of the root node to true
    root->color = true;

    // Initialize the visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
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

    return 0;
}

// <END-OF-CODE>
