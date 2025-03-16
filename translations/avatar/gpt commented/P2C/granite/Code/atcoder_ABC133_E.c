
#include <stdio.h>  // Include standard input/output library
#include <stdlib.h>  // Include standard library for dynamic memory allocation
#include <limits.h>  // Include limits library for INT_MAX

typedef struct Node {
    int data;  // Data stored in the node
    struct Node *next;  // Pointer to the next node in the adjacency list
} Node;

typedef struct Graph {
    int V;  // Number of vertices in the graph
    int E;  // Number of edges in the graph
    Node **adj;  // Array of adjacency lists
} Graph;

// Function to create a new node
Node *newNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = newNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Function to perform depth-first search (DFS) and count valid colorings
long long dfs(int fro, int to, int f, int *colorNum, int mod, Graph *graph) {
    long long caseNum = f;  // Initialize case number with the current color
    int color = *colorNum;  // Get the available color for the current node
    
    // Iterate through all adjacent nodes in the graph
    Node *temp = graph->adj[fro];
    while (temp!= NULL) {
        if (temp->data == to) {  // Skip the node we came from to avoid cycles
            temp = temp->next;
            continue;
        }
        int pat = dfs(temp->data, fro, color - 1, colorNum, mod, graph);  // Recursively call DFS for the adjacent node
        if (pat == 0) {  // If no valid coloring is found, break out
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % mod;  // Update the case number with the valid patterns found
        color--;  // Decrease the available colors for the next node
        temp = temp->next;
    }
    
    return caseNum;  // Return the total valid colorings found
}

int main() {
    int N, K;  // Read the number of nodes (N) and the number of colors (K) from input
    scanf("%d %d", &N, &K);
    
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = N;  // Set the number of vertices in the graph
    graph->E = N - 1;  // Set the number of edges in the graph
    graph->adj = (Node **)malloc(N * sizeof(Node *));  // Allocate memory for the adjacency list array
    for (int i = 0; i < N; i++) {
        graph->adj[i] = NULL;  // Initialize each adjacency list as empty
    }
    
    // Read the edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;  // Read each edge
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);  // Add edge from a to b (0-indexed)
        addEdge(graph, b - 1, a - 1);  // Add edge from b to a (0-indexed)
    }
    
    int mod = 1000000007;  // Define a modulus for the result to prevent overflow
    int colorNum = K - 1;  // Determine the number of available colors for the first node
    
    long long ans = dfs(0, -1, K, &colorNum, mod, graph);  // Start the DFS from the root node (0) with no parent (-1) and K colors
    
    printf("%lld\n", ans);  // Print the final answer which is the number of valid colorings
    
    return 0;
}

Translate the above C code to Java and end with comment "