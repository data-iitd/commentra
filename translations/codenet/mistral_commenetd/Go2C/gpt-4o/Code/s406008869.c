#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
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

// Function to print the edges of the graph
void printEdges(Graph* graph) {
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform Depth First Search traversal
int dfs(Graph* graph, int v, bool* visited) {
    // Check if all nodes are visited
    bool allVisited = true;
    for (int i = 1; i < graph->numVertices; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }

    // If all nodes are visited, return 1 for this strongly connected component
    if (allVisited) {
        return 1;
    }

    // Initialize a counter to store the size of the strongly connected component
    int count = 0;
    visited[v] = true;

    // Iterate through the neighbors of the current node 'v'
    Node* temp = graph->adjLists[v];
    while (temp) {
        int ne = temp->data;
        if (!visited[ne]) {
            count += dfs(graph, ne, visited);
        }
        temp = temp->next;
    }

    // Mark the current node as unvisited for further searches
    visited[v] = false;
    return count;
}

// Main function to read input and call the printEdges and dfs functions
int main() {
    int n, m;
    // Read the number of nodes and edges from the standard input
    scanf("%d %d", &n, &m);

    // Create a graph with n vertices
    Graph* graph = createGraph(n + 1);

    // Read the edges of the graph from the standard input and add them to the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a, b);
    }

    // Call the printEdges function to print the edges of the graph
    // printEdges(graph);

    // Initialize a boolean array to keep track of visited nodes
    bool* visited = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    // Call the dfs function on the first node and print the size of the strongly connected component
    int count = dfs(graph, 1, visited);
    printf("%d\n", count);

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    free(visited);

    return 0;
}

// <END-OF-CODE>
