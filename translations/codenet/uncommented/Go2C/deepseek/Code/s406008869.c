#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int n, m;
int e[MAXN+1][MAXN+1];
int visited[MAXN+1];

void printEdge() {
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 1; j <= n; j++) {
            if (e[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int dfs(int v) {
    visited[v] = 1;
    // printf("Visiting %d\n", v);

    int comp = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = 0;
        }
    }

    if (comp) {
        return 1;
    }

    int count = 0;
    for (int ne = 1; ne <= n; ne++) {
        if (e[v][ne] && !visited[ne]) {
            // printf("ne=%d\n", ne);
            count += dfs(ne);
            visited[ne] = 0; // Backtrack
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    // printEdge();

    visited[1] = 1;
    int count = dfs(1);
    printf("%d\n", count);

    return 0;
}
