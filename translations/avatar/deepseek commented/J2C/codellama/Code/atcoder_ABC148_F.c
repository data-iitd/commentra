
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100000

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to do DFS traversal.  It uses recursive DFS(depth
// first search)
void DFSUtil(struct Graph* graph, int v, int* d, int* e) {
    // Mark the current node as visited and print it
    d[v] = 0;

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl != NULL) {
        int adj = pCrawl->dest;

        if (d[adj] == INT_MAX) {
            DFSUtil(graph, adj, d, e);
        }

        pCrawl = pCrawl->next;
    }

    // Mark the current node as visited and print it
    e[v] = 0;
}

// The function to do DFS traversal.  It uses recursive DFSUtil()
void DFS(struct Graph* graph, int u, int v) {
    // Initialize distance array d[] and e[]
    int d[graph->V];
    int e[graph->V];
    for (int i = 0; i < graph->V; i++) {
        d[i] = INT_MAX;
        e[i] = INT_MAX;
    }

    // Initialize distance of source as 0
    d[u] = 0;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, u, d, e);

    // Initialize distance of source as 0
    e[v] = 0;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, v, d, e);

    // Find the maximum value of e[i] where d[i] < e[i]
    int q = -1;
    for (int i = 0; i < graph->V; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result based on the maximum value found
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }
}

// Driver program to test above functions
int main() {
    // Create a graph with 4 vertices
    int V = 4;
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // DFS traversal of the constructed graph
    DFS(graph, 0, 3);

    return 0;
}

