#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **e;
int n, m;

void printEdge(int **e) {
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 0; e[i][j] != -1; j++) {
            printf("%d ", e[i][j]);
        }
        printf("\n");
    }
}

int dfs(int v, bool *visited) {
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false;
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
        visited[ne] = true;
        count += dfs(ne, visited);
        visited[ne] = false;
    }
    return count;
}

int main() {
    scanf("%d %d", &n, &m);

    e = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        e[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            e[i][j] = -1; // Initialize with -1 to mark the end of the list
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = 0; e[a][j] != -1; j++);
        e[a][j] = b; // Add edge a -> b
        for (int j = 0; e[b][j] != -1; j++);
        e[b][j] = a; // Add edge b -> a
    }

    // printEdge(e);

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
