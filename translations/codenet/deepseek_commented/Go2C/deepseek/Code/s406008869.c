#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int n, m;
int e[MAXN+1][MAXN+1];
int visited[MAXN+1];

// Function to print the edges of the graph in a readable format
void printEdge() {
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 1; j <= n; j++) {
            if (e[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v) {
    // Mark the current node as visited
    visited[v] = 1;

    int count = 1;
    for (int ne = 1; ne <= n; ne++) {
        if (e[v][ne] == 1 && !visited[ne]) {
            count += dfs(ne);
        }
    }
    return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
    scanf("%d %d", &n, &m);

    // Initialize the graph edges
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = 0;
        }
    }

    // Read the edges and populate the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    // printEdge();

    // Initialize visited array and start DFS from node 1
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    int count = dfs(1);
    printf("%d\n", count);

    return 0;
}
