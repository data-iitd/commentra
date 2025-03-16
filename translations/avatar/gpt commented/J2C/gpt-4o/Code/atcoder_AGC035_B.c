#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int *edges;
    int edgeCount;
} Node;

Node *createGraph(int numNode) {
    Node *graph = malloc(numNode * sizeof(Node));
    for (int i = 0; i < numNode; i++) {
        graph[i].edges = malloc(numNode * sizeof(int));
        graph[i].edgeCount = 0;
    }
    return graph;
}

void addEdge(Node *graph, int a, int b) {
    graph[a].edges[graph[a].edgeCount++] = b;
    graph[b].edges[graph[b].edgeCount++] = a;
}

void dfs(Node *graph, int *visited, bool *odd, int crt, int parent, char *output, int *outputIndex) {
    visited[crt] = 1; // Mark the current node as visited

    for (int i = 0; i < graph[crt].edgeCount; i++) {
        int child = graph[crt].edges[i];

        // Skip the parent node and already visited nodes
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            // If the child has been fully processed, append the edge to output
            *outputIndex += sprintf(output + *outputIndex, "%d %d\n", crt + 1, child + 1);
            odd[crt] = !odd[crt]; // Toggle the odd/even state
        } else {
            // Recursively call DFS on the child node
            dfs(graph, visited, odd, child, crt, output, outputIndex);

            // Check the odd/even state of the child node after DFS
            if (odd[child]) {
                *outputIndex += sprintf(output + *outputIndex, "%d %d\n", child + 1, crt + 1);
                odd[child] = !odd[child]; // Toggle the state
            } else {
                *outputIndex += sprintf(output + *outputIndex, "%d %d\n", crt + 1, child + 1);
                odd[crt] = !odd[crt]; // Toggle the state
            }
        }
    }
    visited[crt] = 2; // Mark the current node as fully processed
}

int main() {
    // Initialize input variables
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    // Create the graph
    Node *graph = createGraph(numNode);

    // Read edges and populate the graph
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1); // Convert to 0-indexed
    }

    // Check if the number of edges is odd; if so, output -1 and exit
    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    // Initialize arrays for tracking visited nodes and odd/even connections
    int *visited = calloc(numNode, sizeof(int));
    bool *odd = calloc(numNode, sizeof(bool));
    char output[100000]; // Buffer for output
    int outputIndex = 0; // Current index in output buffer

    // Perform depth-first search starting from node 0
    dfs(graph, visited, odd, 0, -1, output, &outputIndex);

    // Output the result
    printf("%s", output);

    // Free allocated memory
    for (int i = 0; i < numNode; i++) {
        free(graph[i].edges);
    }
    free(graph);
    free(visited);
    free(odd);

    return 0;
}

// <END-OF-CODE>
