#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    Node** adjLists;
    int numVertices;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
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

// Recursive DFS function to count valid colorings
long long dfs(Graph* graph, int fro, int to, int f, int K) {
    long long caseNum = f;  // Initialize case number with the current color
    int colorNum = (f == K) ? (K - 1) : (K - 2);  // Determine available colors for the next node

    for (Node* u = graph->adjLists[fro]; u != NULL; u = u->next) {
        if (u->vertex == to) {  // Skip the node we came from
            continue;
        }
        long long pat = dfs(graph, u->vertex, fro, colorNum, K);  // Recursive call
        if (pat == 0) {  // If no valid coloring is found
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;  // Update case number
        colorNum--;  // Decrease available colors for the next node
    }

    return caseNum;  // Return total valid colorings found
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);  // Read number of nodes and colors

    Graph* graph = createGraph(N);  // Create the graph

    // Read N-1 edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);  // Add edge (0-indexed)
    }

    // Start DFS from the root node (0) with no parent (-1) and K colors
    long long ans = dfs(graph, 0, -1, K, K);

    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory (not shown for brevity)
    // Free the graph and its nodes here...

    return 0;
}

// <END-OF-CODE>
