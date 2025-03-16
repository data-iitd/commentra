#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    Edge edges[MAXN];
    int edge_count;
} Node;

Node graph[MAXN];
int ans[MAXN];
int n;

void dfs(int to, int color, int parent) {
    int k = 1;
    for (int i = 0; i < graph[to].edge_count; i++) {
        Edge e = graph[to].edges[i];
        if (e.to == parent) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(e.to, k, to);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        graph[i].edge_count = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        Edge e1 = {i, b};
        Edge e2 = {i, a};
        graph[a].edges[graph[a].edge_count++] = e1;
        graph[b].edges[graph[b].edge_count++] = e2;
    }

    dfs(0, -1, -1);

    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }

    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

