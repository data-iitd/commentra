#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000 // Define a maximum number of nodes

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjList;
    bool* seen;
    int count;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
Graph* createGraph(int m) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (Node**)malloc((m + 1) * sizeof(Node*));
    graph->seen = (bool*)malloc((m + 1) * sizeof(bool));
    graph->count = 0;

    for (int i = 0; i <= m; i++) {
        graph->adjList[i] = NULL;
        graph->seen[i] = false;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int x, int y) {
    Node* newNodeY = createNode(y);
    newNodeY->next = graph->adjList[x];
    graph->adjList[x] = newNodeY;

    Node* newNodeX = createNode(x);
    newNodeX->next = graph->adjList[y];
    graph->adjList[y] = newNodeX;
}

// Depth-first search method to detect cycles
int dfs(Graph* graph, int child, int par) {
    if (graph->seen[child]) return 1; // If child is already seen, return cycle
    graph->seen[child] = true; // Mark the child as seen
    for (Node* i = graph->adjList[child]; i != NULL; i = i->next) { // Iterate over neighbors of child
        if (i->data != par) { // Avoid going back to parent
            graph->count++; // Increment count for each edge traversed
            if (dfs(graph, i->data, child) == 1) return 1; // If cycle is detected, return cycle
        }
    }
    return 0; // Return path if no cycle is detected
}

// Main function to handle input and output
int main() {
    int m, n;
    scanf("%d %d", &m, &n); // Number of nodes and edges
    Graph* graph = createGraph(m);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Read edge from and to
        addEdge(graph, x, y); // Add edge to adjacency list
    }

    int toremove = 0; // Initialize removal count
    for (int i = 1; i <= m; i++) {
        if (!graph->seen[i]) { // If node is not visited
            graph->count = 0; // Reset count for each DFS call
            if (dfs(graph, i, 0) == 1) { // If cycle is detected
                if (graph->count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
            }
        }
    }
    
    if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
    printf("%d\n", toremove); // Print the final removal count

    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph->seen);
    free(graph);
    
    return 0;
}

// <END-OF-CODE>
