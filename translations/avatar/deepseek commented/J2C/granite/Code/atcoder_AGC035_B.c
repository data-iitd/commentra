
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);
    
    // Initializing adjacency lists for each node
    int** connect = (int**)malloc(numNode * sizeof(int*));
    for (int i = 0; i < numNode; i++) {
        connect[i] = (int*)malloc(numNode * sizeof(int));
        for (int j = 0; j < numNode; j++) {
            connect[i][j] = 0;
        }
    }
    
    // Reading edges and populating the adjacency lists
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a - 1][b - 1] = 1; // Subtracting 1 from node indices to convert to zero-based index
        connect[b - 1][a - 1] = 1; // Subtracting 1 from node indices to convert to zero-based index
    }
    
    // Checking if the number of edges is odd
    if (numEdge % 2!= 0) {
        printf("-1\n"); // Printing -1 if the number of edges is odd
        return 0; // Returning from the main method
    }
    
    // Initializing arrays for DFS
    int* visited = (int*)malloc(numNode * sizeof(int));
    int* odd = (int*)malloc(numNode * sizeof(int));
    char* print = (char*)malloc(numEdge * 10 * sizeof(char)); // Assuming each line of print has a maximum length of 10 characters
    int printIndex = 0;
    
    // Performing DFS starting from node 0
    dfs(0, -1, connect, visited, odd, print, &printIndex);
    
    // Outputting the result
    printf("%s", print);
    
    // Freeing dynamically allocated memory
    for (int i = 0; i < numNode; i++) {
        free(connect[i]);
    }
    free(connect);
    free(visited);
    free(odd);
    free(print);
    
    return 0;
}

// DFS method to traverse the graph
void dfs(int crt, int parent, int** connect, int* visited, int* odd, char* print, int* printIndex) {
    visited[crt] = 1; // Marking the current node as visited
    int* crtConnect = connect[crt]; // Getting the adjacency list of the current node
    
    // Traversing each child node of the current node
    for (int child = 0; child < numNode; child++) {
        if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
            continue;
        } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
            sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1); // Adding the edge to the print array
            odd[crt] =!odd[crt];
            printIndex += 10; // Incrementing the print index
        } else { // Recursively calling dfs for unvisited child nodes
            dfs(child, crt, connect, visited, odd, print, printIndex);
            if (odd[child]) { // Updating the print and odd arrays based on the child's result
                sprintf(print + printIndex, "%d %d\n", child + 1, crt + 1); // Adding the edge to the print array
                odd[child] =!odd[child];
                printIndex += 10; // Incrementing the print index
            } else {
                sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1); // Adding the edge to the print array
                odd[crt] =!odd[crt];
                printIndex += 10; // Incrementing the print index
            }
        }
    }
    visited[crt] = 2; // Marking the current node as fully processed
}

