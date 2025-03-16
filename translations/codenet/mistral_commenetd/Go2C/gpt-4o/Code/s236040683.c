#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a node in the graph.
typedef struct Node {
    int *to;      // Array of neighbors
    int size;     // Number of neighbors
    int capacity; // Capacity of the neighbors array
} Node;

// Function to initialize a Node
void initNode(Node *node) {
    node->size = 0;
    node->capacity = 2; // Initial capacity
    node->to = malloc(node->capacity * sizeof(int));
}

// Function to add a neighbor to a Node
void addNeighbor(Node *node, int neighbor) {
    if (node->size >= node->capacity) {
        node->capacity *= 2; // Double the capacity
        node->to = realloc(node->to, node->capacity * sizeof(int));
    }
    node->to[node->size++] = neighbor;
}

// Function to free the memory allocated for a Node
void freeNode(Node *node) {
    free(node->to);
}

int main() {
    int N, M;
    
    // Read the number of nodes N and edges M from the input.
    scanf("%d %d", &N, &M);

    // Create an array of Nodes.
    Node *nodes = malloc(N * sizeof(Node));
    
    // Initialize each Node.
    for (int i = 0; i < N; i++) {
        initNode(&nodes[i]);
    }

    // Process each edge by adding it to the corresponding nodes.
    for (int i = 0; i < M; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--; // Convert to 0-based index
        to--;   // Convert to 0-based index

        // Add the edge to both nodes.
        addNeighbor(&nodes[from], to);
        addNeighbor(&nodes[to], from);
    }

    // Print the number of neighbors for each node.
    for (int i = 0; i < N; i++) {
        printf("%d\n", nodes[i].size);
    }

    // Free the allocated memory for each Node.
    for (int i = 0; i < N; i++) {
        freeNode(&nodes[i]);
    }
    free(nodes); // Free the array of Nodes

    return 0;
}

// <END-OF-CODE>
