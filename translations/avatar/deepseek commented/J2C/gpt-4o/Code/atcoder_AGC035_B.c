#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000 // Define a maximum number of nodes

// Global variables
int connect[MAX_NODES][MAX_NODES]; // Adjacency matrix
int numEdges[MAX_NODES]; // To store the number of edges for each node
int visited[MAX_NODES]; // To track visited nodes
bool odd[MAX_NODES]; // To track odd/even status
char print[10000]; // To store the output
int printIndex = 0; // To track the current index in the output

// DFS function to traverse the graph
void dfs(int crt, int parent) {
    visited[crt] = 1; // Marking the current node as visited

    // Traversing each child node of the current node
    for (int child = 0; child < MAX_NODES; child++) {
        if (connect[crt][child] == 1) { // If there is an edge
            if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
                continue;
            } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
                sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1);
                printIndex += 6; // Update index for the next output
                odd[crt] = !odd[crt];
            } else { // Recursively calling dfs for unvisited child nodes
                dfs(child, crt);
                if (odd[child]) { // Updating the print and odd arrays based on the child's result
                    sprintf(print + printIndex, "%d %d\n", child + 1, crt + 1);
                    printIndex += 6; // Update index for the next output
                    odd[child] = !odd[child];
                } else {
                    sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1);
                    printIndex += 6; // Update index for the next output
                    odd[crt] = !odd[crt];
                }
            }
        }
    }
    visited[crt] = 2; // Marking the current node as fully processed
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge); // Reading the number of nodes and edges

    // Initializing adjacency matrix and edge counts
    for (int i = 0; i < numNode; i++) {
        numEdges[i] = 0; // Initialize edge count
        for (int j = 0; j < numNode; j++) {
            connect[i][j] = 0; // Initialize adjacency matrix
        }
    }

    // Reading edges and populating the adjacency matrix
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Reading node a and b
        a--; b--; // Convert to zero-based index
        connect[a][b] = 1; // Adding edge from a to b
        connect[b][a] = 1; // Adding edge from b to a
        numEdges[a]++;
        numEdges[b]++;
    }

    // Checking if the number of edges is odd
    if (numEdge % 2 != 0) {
        printf("-1\n"); // Printing -1 if the number of edges is odd
        return 0; // Returning from the main method
    }

    // Initializing arrays for DFS
    for (int i = 0; i < numNode; i++) {
        visited[i] = 0; // Initialize visited array
        odd[i] = false; // Initialize odd array
    }

    // Performing DFS starting from node 0
    dfs(0, -1);

    // Outputting the result
    printf("%s", print);
    return 0;
}

// <END-OF-CODE>
