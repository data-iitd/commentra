
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
    int *edges;
    int size;
} List;

void dfs(int u, int *d, List *edges, int *visited) {
    for (int i = 0; i < edges[u].size; i++) {
        int nu = edges[u].edges[i];
        if (visited[nu] == 0) {
            visited[nu] = 1;
            d[nu] = d[u] + 1;
            dfs(nu, d, edges, visited);
        }
    }
}

int main() {
    int N, u, v;
    scanf("%d", &N);
    scanf("%d", &u);
    scanf("%d", &v);
    List *edges = (List *)malloc(sizeof(List) * N);
    for (int i = 0; i < N; i++) {
        edges[i].edges = (int *)malloc(sizeof(int) * MAX_SIZE);
        edges[i].size = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        edges[a - 1].edges[edges[a - 1].size++] = b - 1;
        edges[b - 1].edges[edges[b - 1].size++] = a - 1;
    }
    int *d = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u - 1] = 0;
    int *visited = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    dfs(u - 1, d, edges, visited);
    int *e = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v - 1] = 0;
    dfs(v - 1, e, edges, visited);
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }
    return 0;
}

