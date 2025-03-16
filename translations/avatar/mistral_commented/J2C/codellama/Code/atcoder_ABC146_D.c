
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

typedef struct Edge {
    int id;
    int to;
} Edge;

int n;
int ans[MAX];
Edge *g[MAX];

void dfs(int to, int color, int parents) {
    int k = 1;
    for (int i = 0; i < g[to]->size; i++) {
        Edge *e = g[to]->arr[i];
        if (e->to == parents) continue;
        if (k == color) k++;
        ans[e->id] = k;
        dfs(e->to, k, to);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        g[i] = (Edge *)malloc(sizeof(Edge) * MAX);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Edge *e = (Edge *)malloc(sizeof(Edge));
        e->id = i;
        e->to = b;
        g[a]->arr[g[a]->size++] = e;
        e = (Edge *)malloc(sizeof(Edge));
        e->id = i;
        e->to = a;
        g[b]->arr[g[b]->size++] = e;
    }
    dfs(0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        max = max > ans[i] ? max : ans[i];
    }
    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

