#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

// Structure to represent a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent an adjacency list
typedef struct Graph {
    Node** adjLists;
    int numVertices;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) method to explore the graph
int dfs(Graph* graph, int child, int par, bool* seen, int* count) {
    if (seen[child]) return 1; // Cycle found
    seen[child] = true;
    (*count)++;

    Node* temp = graph->adjLists[child];
    while (temp) {
        if (temp->data != par) {
            if (dfs(graph, temp->data, child, seen, count) == 1) return 1; // Check for cycles
        }
        temp = temp->next;
    }
    return 0; // No cycle found
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Graph* graph = createGraph(m + 1);
    bool* seen = calloc(m + 1, sizeof(bool));
    int toremove = 0;

    // Read the edges and populate the graph
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
    }

    // Iterate through all nodes to check for unvisited nodes
    for (int i = 1; i <= m; i++) {
        if (!seen[i]) {
            int count = 0; // Reset count for the new component
            if (dfs(graph, i, -1, seen, &count) == 1) {
                if (count % 2 == 1) toremove++;
            }
        }
    }

    // Adjust the number of nodes to remove if the remaining nodes are odd
    if ((m - toremove) % 2 == 1) toremove++;

    // Output the result: number of nodes to remove
    printf("%d\n", toremove);

    // Free allocated memory
    for (int i = 0; i < m + 1; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    free(seen);

    return 0;
}

// <END-OF-CODE>
