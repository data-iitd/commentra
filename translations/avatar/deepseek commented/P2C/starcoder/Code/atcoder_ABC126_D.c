
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure to represent each node in the graph
typedef struct Node {
    int val;
    int color;
    struct Node *a[100000];
} Node;

// Read the number of nodes in the graph
int n;
scanf ( "%d", &n );

// Create a list to store all nodes
Node *nodes[100000];
for ( int i = 0 ; i < n ; i ++ ) {
    nodes[i] = ( Node * ) malloc ( sizeof ( Node ) );
    nodes[i]->val = 0;
    nodes[i]->color = 0;
    for ( int j = 0 ; j < 100000 ; j ++ ) {
        nodes[i]->a[j] = NULL;
    }
}

// Read each edge in the graph and establish connections between nodes
for ( int i = 0 ; i < n - 1 ; i ++ ) {
    int u, v, w;
    scanf ( "%d%d%d", &u, &v, &w );
    Node *node1 = nodes[u - 1];
    Node *node2 = nodes[v - 1];
    node1->val = u;
    node2->val = v;
    node1->a[i] = node2;
    node2->a[i] = node1;
}

// Set the root node to the first node in the list
Node *root = nodes[0];

// Set the color of the root node to True
root->color = 1;

// Initialize a set to keep track of visited nodes
Node *nodeSet[100000];

// Define the traverse function to recursively traverse the graph
void traverse ( Node *node, int distance ) {
    if ( nodeSet[node->val] ) {
        return;
    }
    else {
        nodeSet[node->val] = node;
    }
    for ( int i = 0 ; i < 100000 ; i ++ ) {
        if ( node->a[i] ) {
            Node *adjNode = node->a[i];
            int dis = node->a[i]->val;
            if ( ( distance + dis ) % 2 == 0 ) {
                adjNode->color = root->color;
            }
            else {
                adjNode->color =!root->color;
            }
            traverse ( adjNode, distance + dis );
        }
    }
}

// Call the traverse function starting from the root node with a distance of 0
traverse ( root, 0 );

// Print the color of each node
for ( int i = 0 ; i < n ; i ++ ) {
    Node *node = nodes[i];
    if ( node->color ) {
        printf ( "1\n" );
    }
    else {
        printf ( "0\n" );
    }
}

