

#include <stdio.h>
#include <stdlib.h>

// Define the Node struct to represent each node in the graph
typedef struct Node {
    int val;
    int color;
    struct Node *a;
} Node;

// Define the traverse function to recursively traverse the graph
void traverse(Node *node, int distance) {
    if (node->color!= -1) {
        return;
    }
    node->color = distance % 2;
    struct Node *temp = node->a;
    while (temp!= NULL) {
        traverse(temp, distance + 1);
        temp = temp->a;
    }
}

int main() {
    // Read the number of nodes in the graph
    int n;
    scanf("%d", &n);

    // Create an array to store all nodes
    Node *nodes = (Node *)malloc(sizeof(Node) * n);

    // Read each edge in the graph and establish connections between nodes
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        nodes[u - 1].val = u;
        nodes[v - 1].val = v;
        nodes[u - 1].a = &nodes[v - 1];
        nodes[v - 1].a = &nodes[u - 1];
    }

    // Set the color of all nodes to -1
    for (int i = 0; i < n; i++) {
        nodes[i].color = -1;
    }

    // Set the color of the root node to 0
    nodes[0].color = 0;

    // Call the traverse function starting from the root node with a distance of 0
    traverse(&nodes[0], 0);

    // Print the color of each node
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i].color);
    }

    return 0;
}

Translate the above C code to Java and end with comment "