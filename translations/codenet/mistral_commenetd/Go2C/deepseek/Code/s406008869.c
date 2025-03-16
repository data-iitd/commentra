#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

int n, m;
int e[MAX_NODES + 1][MAX_NODES + 1];
int visited[MAX_NODES + 1];

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

int dfs(int v, int *count) {
    visited[v] = 1;

    for (int ne = 1; ne <= n; ne++) {
        if (e[v][ne] == 0 || visited[ne]) {
            continue;
        }
        (*count)++;
        dfs(ne, count);
        (*count)--;
    }

    int comp = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = 0;
            break;
        }
    }

    if (comp) {
        return 1;
    }

    return *count;
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

    int count = 0;
    dfs(1, &count);
    printf("%d\n", count);

    return 0;
}

