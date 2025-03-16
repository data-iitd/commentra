#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list representation of the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// Array to track visited nodes
bool* visited;
// Array to store colors of nodes for bipartite checking
int* color;
// Counters for specific conditions
long one;
long bipartite;
long count;
// Flag to check if the graph is not bipartite
bool mujun;

// Depth-First Search (DFS) method to explore the graph
int dfs(Graph* graph, int a, int c) {
    // If the node has already been visited
    if (visited[a]) {
        // Check for color conflict indicating the graph is not bipartite
        if (color[a] >= 0 && color[a] != c) mujun = true;
        return 0;
    }
    // Mark the node as visited and assign it a color
    visited[a] = true;
    color[a] = c;
    int total = 1; // Count the current node

    // Recursively visit all adjacent nodes with alternate color
    Node* temp = graph->adjList[a];
    while (temp != NULL) {
        total += dfs(graph, temp->data, 1 - c);
        temp = temp->next;
    }
    return total; // Return the total count of nodes in this component
}

// Function to create a new adjacency list node
Node* newAdjListNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = newAdjListNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Main execution method for the program
void run() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create the graph
    Graph* graph = createGraph(n);

    // Read edges and populate the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1); // Add edge to the graph
    }

    // Initialize visited and color arrays
    visited = (bool*)malloc(n * sizeof(bool));
    color = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        color[i] = -1; // Set all colors to -1 (uncolored)

    // Initialize counters
    one = 0;
    bipartite = 0;
    count = 0;

    // Iterate through all nodes to find connected components
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue; // Skip already visited nodes
        count++; // Increment component count
        mujun = false; // Reset bipartite flag
        int kind = dfs(graph, i, 0); // Perform DFS starting from node i

        // Update counters based on the results of DFS
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }

    // Calculate the total based on the counts of components
    long total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;

    // Output the final result
    printf("%ld\n", total);

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);
    free(visited);
    free(color);
}

// Main method to start the program
int main() {
    run();
    return 0;
}
