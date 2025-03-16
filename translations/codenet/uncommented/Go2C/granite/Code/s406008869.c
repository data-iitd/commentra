
#include <stdio.h>
#include <stdbool.h>

int n, m;
int **e;
bool *visited;

void printEdge() {
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < e[i][0]; j++) {
            printf("%d ", e[i][j+1]);
        }
        printf("\n");
    }
}

int dfs(int v) {
    visited[v] = true;

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
    for (int j = 1; j <= e[v][0]; j++) {
        int ne = e[v][j];
        if (visited[ne]) {
            continue;
        }
        visited[ne] = true;
        count += dfs(ne);
        visited[ne] = false;
    }
    return count;
}

int main() {
    scanf("%d %d", &n, &m);

    e = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        e[i] = (int *)malloc(sizeof(int) * (m + 1));
        e[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][0]++;
        e[a][e[a][0]] = b;
        e[b][0]++;
        e[b][e[b][0]] = a;
    }
    // printEdge();

    visited = (bool *)malloc(sizeof(bool) * (n + 1));
    visited[1] = true;
    int count = dfs(1);
    printf("%d\n", count);

    return 0;
}
