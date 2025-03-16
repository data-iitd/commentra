#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **e;
int n, m;

// Function to print the edges of the graph in a readable format
void printEdge(int **e) {
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 0; e[i][j] != -1; j++) {
            printf("%d ", e[i][j]);
        }
        printf("\n");
    }
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v, bool *visited) {
    // Mark the current node as visited
    visited[v] = true;

    // Check if all nodes are visited
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false;
            break;
        }
    }

    if (comp) {
        return 1;
    }

    int count = 0;
    for (int j = 0; e[v][j] != -1; j++) {
        int ne = e[v][j];
        if (visited[ne]) {
            continue;
        }
        count += dfs(ne, visited);
        visited[ne] = false;
    }
    return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
    scanf("%d %d", &n, &m);

    // Initialize the graph edges
    e = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        e[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j < n + 1; j++) {
<<<<<<< HEAD
            e[i][j] = -1; // Initialize with -1 to mark the end of the list
=======
            e[i][j] = -1; // Use -1 to indicate the end of the list
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Read the edges and populate the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = 0; e[a][j] != -1; j++);
        e[a][j] = b;
        for (int j = 0; e[b][j] != -1; j++);
        e[b][j] = a;
    }
    // printEdge(e);

    // Initialize visited array and start DFS from node 1
    bool *visited = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    visited[1] = true;
    int count = dfs(1, visited);
    printf("%d\n", count);

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(e[i]);
    }
    free(e);
    free(visited);

    return 0;
}

// <END-OF-CODE>
