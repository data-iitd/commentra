
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the struct to store the connectivity information for each node.
struct connect {
    int *neighbors;
    int numNeighbors;
};

// Defining the struct to store the visited status and odd component for each node.
struct visited {
    int status;
    bool odd;
};

// Defining the function to perform bipartite traversal.
void dfs(int crt, int parent, struct connect *connect, struct visited *visited, char *print) {
    // Marking the current node as visited.
    visited[crt].status = 1;

    // Iterating through the neighbors of the current node.
    for (int i = 0; i < connect[crt].numNeighbors; i++) {
        int child = connect[crt].neighbors[i];

        // Skipping the neighbor if it is the parent node or already visited.
        if (child == parent || visited[child].status == 1) {
            continue;
        }

        // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        // Otherwise, we swap the components and continue the traversal.
        if (visited[child].status == 2) {
            printf("%d %d\n", crt + 1, child + 1);
            visited[crt].odd = !visited[crt].odd;
        } else {
            dfs(child, crt, connect, visited, print);
            if (visited[child].odd) {
                printf("%d %d\n", child + 1, crt + 1);
                visited[child].odd = !visited[child].odd;
            } else {
                printf("%d %d\n", crt + 1, child + 1);
                visited[crt].odd = !visited[crt].odd;
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited[crt].status = 2;
}

// Defining the main function to read input and perform bipartite traversal.
int main() {
    // Reading the number of nodes and edges from the standard input stream.
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    // Initializing the connect array to store the list of neighbors for each node.
    struct connect *connect = (struct connect *)malloc(numNode * sizeof(struct connect));
    for (int i = 0; i < numNode; i++) {
        connect[i].neighbors = (int *)malloc(numNode * sizeof(int));
        connect[i].numNeighbors = 0;
    }

    // Reading the edges and adding them to the connect array.
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a - 1].neighbors[connect[a - 1].numNeighbors++] = b - 1;
        connect[b - 1].neighbors[connect[b - 1].numNeighbors++] = a - 1;
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    // Initializing the visited, odd, and print arrays and objects.
    struct visited *visited = (struct visited *)malloc(numNode * sizeof(struct visited));
    for (int i = 0; i < numNode; i++) {
        visited[i].status = 0;
        visited[i].odd = false;
    }
    char *print = (char *)malloc(numNode * numNode * sizeof(char));

    // Calling the dfs method with the first node and -1 as the parent node.
    dfs(0, -1, connect, visited, print);

    // Printing the output.
    printf("%s", print);

    // Freeing the memory allocated for the connect, visited, and print arrays and objects.
    for (int i = 0; i < numNode; i++) {
        free(connect[i].neighbors);
    }
    free(connect);
    free(visited);
    free(print);

    return 0;
}

