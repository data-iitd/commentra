#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100000

// Structure to represent an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent an adjacency list
typedef struct Graph {
    Node** adjLists;
    int numVertices;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with N vertices
Graph* createGraph(int N) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = N;
    graph->adjLists = malloc(N * sizeof(Node*));
    
    for (int i = 0; i < N; i++) {
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

// Depth-first search (DFS) to calculate distances from a given node
void dfs(int u, int* d, Graph* graph) {
    for (Node* temp = graph->adjLists[u]; temp != NULL; temp = temp->next) {
        int nu = temp->vertex;
        if (d[nu] == INT_MAX) { // If the node has not been visited
            d[nu] = d[u] + 1; // Update the distance
            dfs(nu, d, graph); // Recursively visit the next node
        }
    }
}

int main() {
    // Initialize the scanner to read input
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--; // Convert to zero-based index
    v--; // Convert to zero-based index

    // Create a graph to represent the edges
    Graph* graph = createGraph(N);

    // Read the edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        addEdge(graph, a, b); // Add edge to the graph
    }

    // Initialize distance array for the first node (u)
    int* d = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; // Set initial distances to infinity
    }
    d[u] = 0; // Distance to itself is 0

    // Perform DFS from node u to calculate distances
    dfs(u, d, graph);

    // Initialize distance array for the second node (v)
    int* e = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX; // Set initial distances to infinity
    }
    e[v] = 0; // Distance to itself is 0

    // Perform DFS from node v to calculate distances
    dfs(v, e, graph);

    // Find the maximum distance from node u to any node that is closer to v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) { // Check if node i is closer to u than to v
            if (e[i] > q) { // Update q if the distance to v is greater
                q = e[i];
            }
        }
    }

    // Output the result based on the maximum distance found
    if (q <= 0) {
        printf("0\n"); // If no valid distance found, print 0
    } else {
        printf("%d\n", q - 1); // Print the maximum distance minus 1
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    free(d);
    free(e);

    return 0;
}

// <END-OF-CODE>
