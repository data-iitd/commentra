
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Structure to represent an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure to represent an adjacency list
typedef struct AdjList {
    AdjListNode* head;  // pointer to head node of list
} AdjList;

// Structure to represent a graph
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// A utility function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to do DFS traversal.  It uses recursive dfsUtil()
void DFS(Graph* graph, int v) {
    // Mark the current node as visited and print it
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        if (!visited[pCrawl->dest]) {
            DFS(graph, pCrawl->dest);
        }
        pCrawl = pCrawl->next;
    }
}

// Driver program to test above functions
int main() {
    // Create a graph with 4 vertices
    int V = 4;
    Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // DFS Traversal of the complete graph
    printf("Following is Depth First Traversal (starting from vertex 2) \n");
    DFS(graph, 2);

    return 0;
}

