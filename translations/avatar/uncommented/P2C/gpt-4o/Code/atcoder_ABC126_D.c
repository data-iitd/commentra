#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

typedef struct Node {
    int val;
    bool color;
    struct Node* adj[MAX_NODES];
    int weights[MAX_NODES];
    int adjCount;
} Node;

Node nodes[MAX_NODES];
bool nodeSet[MAX_NODES];

void traverse(Node* node, int distance) {
    int index = node - nodes; // Get the index of the node
    if (nodeSet[index]) {
        return;
    } else {
        nodeSet[index] = true;
    }
    
    for (int i = 0; i < node->adjCount; i++) {
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
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        nodes[i].val = i + 1;
        nodes[i].adjCount = 0;
        nodeSet[i] = false;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node* node1 = &nodes[u - 1];
        Node* node2 = &nodes[v - 1];
        
        node1->adj[node1->adjCount] = node2;
        node1->weights[node1->adjCount] = w;
        node1->adjCount++;
        
        node2->adj[node2->adjCount] = node1;
        node2->weights[node2->adjCount] = w;
        node2->adjCount++;
    }
    
    Node* root = &nodes[0];
    root->color = true;
    
    traverse(root, 0);
    
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
