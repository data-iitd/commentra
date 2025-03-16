#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Define a structure for adjacency list nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for adjacency lists
typedef struct AdjList {
    Node* head;
} AdjList;

// Define a structure for graphs
typedef struct Graph {
    int N;
    AdjList* array;
} Graph;

// Function to create a new adjacency list node
Node* newAdjListNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with N vertices
Graph* createGraph(int N) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->N = N;
    graph->array = (AdjList*)malloc(N * sizeof(AdjList));
    for (int i = 0; i < N; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Recursive function to perform depth-first search (DFS) and count valid colorings
long long dfs(Graph* graph, int fro, int to, int f) {
    long long caseNum = f;  // Initialize case number with the current color
    int colorNum = (f == K) ? K - 1 : K - 2;  // Determine the number of available colors for the next node
    Node* u = graph->array[fro].head;

    // Iterate through all adjacent nodes in the graph
    while (u != NULL) {
        if (u->data == to) {  // Skip the node we came from to avoid cycles
            u = u->next;
            continue;
        }
        long long pat = dfs(graph, u->data, fro, colorNum);  // Recursively call DFS for the adjacent node
        if (pat == 0) {  // If no valid coloring is found, break out
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;  // Update the case number with the valid patterns found
        colorNum -= 1;  // Decrease the available colors for the next node
        u = u->next;
    }

    return caseNum;  // Return the total valid colorings found
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Create a graph with N vertices
    Graph* graph = createGraph(N);

    // Build the graph by reading N-1 edges
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);  // Add edge from a to b (0-indexed)
    }

    // Start the DFS from the root node (0) with no parent (-1) and K colors
    long long ans = dfs(graph, 0, -1, K);

    // Print the final answer which is the number of valid colorings
    printf("%lld\n", ans);

    return 0;
}
