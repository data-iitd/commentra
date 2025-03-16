#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaring necessary structs
typedef struct {
    int numNode;
    int numEdge;
    int** connect;
} Graph;

typedef struct {
    int* visited;
    bool* odd;
    char* print;
} DFS;

// Declaring necessary functions
void readGraph(Graph* graph);
void dfs(Graph* graph, int crt, int parent, DFS* dfs);

int main() {
    Graph graph; // Creating a Graph object to store the graph
    readGraph(&graph); // Reading the graph
    
    // Checking if the number of edges is odd
    if (graph.numEdge % 2 != 0) {
        printf("-1\n"); // Printing -1 if the number of edges is odd
        return 0; // Returning from the main function
    }
    
    // Initializing arrays for DFS
    int* visited = (int*)malloc(graph.numNode * sizeof(int));
    bool* odd = (bool*)malloc(graph.numNode * sizeof(bool));
    char* print = (char*)malloc(graph.numNode * sizeof(char));
    
    // Performing DFS starting from node 0
    DFS dfs;
    dfs.visited = visited;
    dfs.odd = odd;
    dfs.print = print;
    dfs(graph, 0, -1, &dfs);
    
    // Outputting the result
    printf("%s", print);
    free(visited);
    free(odd);
    free(print);
    return 0;
}

// Function to read the graph
void readGraph(Graph* graph) {
    scanf("%d %d", &graph->numNode, &graph->numEdge); // Reading the number of nodes and edges
    graph->connect = (int**)malloc(graph->numNode * sizeof(int*)); // Initializing the adjacency list for each node
    for (int i = 0; i < graph->numNode; i++) {
        graph->connect[i] = (int*)malloc(graph->numNode * sizeof(int)); // Initializing the adjacency list for each node
    }
    
    // Reading edges and populating the adjacency lists
    for (int i = 0; i < graph->numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Reading node a and b
        graph->connect[a - 1][b - 1] = 1; // Adding edge from a to b
        graph->connect[b - 1][a - 1] = 1; // Adding edge from b to a
    }
}

// Function to perform DFS
void dfs(Graph* graph, int crt, int parent, DFS* dfs) {
    dfs->visited[crt] = 1; // Marking the current node as visited
    int** crtConnect = graph->connect[crt]; // Getting the adjacency list of the current node
    
    // Traversing each child node of the current node
    for (int i = 0; i < graph->numNode; i++) {
        if (crtConnect[i] == 1 && i != parent) { // Skipping if the child is the parent or already visited
            continue;
        } else if (dfs->visited[i] == 2) { // Handling the case where the child is part of an already visited cycle
            printf("%d %d\n", crt + 1, i + 1);
            dfs->odd[crt] = !dfs->odd[crt];
        } else { // Recursively calling dfs for unvisited child nodes
            dfs(graph, i, crt, dfs);
            if (dfs->odd[i]) { // Updating the print and odd arrays based on the child's result
                printf("%d %d\n", i + 1, crt + 1);
                dfs->odd[i] = !dfs->odd[i];
            } else {
                printf("%d %d\n", crt + 1, i + 1);
                dfs->odd[crt] = !dfs->odd[crt];
            }
        }
    }
    dfs->visited[crt] = 2; // Marking the current node as fully processed
}

