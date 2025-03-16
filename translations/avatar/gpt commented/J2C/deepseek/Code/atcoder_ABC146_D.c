#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    Edge* edges;
    int edge_count;
} Node;

Node graph[MAX_NODES];
int ans[MAX_NODES - 1];
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
        graph[i].edges = NULL;
        graph[i].edge_count = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        graph[a].edges = (Edge*)realloc(graph[a].edges, (graph[a].edge_count + 1) * sizeof(Edge));
        graph[a].edges[graph[a].edge_count].id = i;
        graph[a].edges[graph[a].edge_count].to = b;
        graph[a].edge_count++;

        graph[b].edges = (Edge*)realloc(graph[b].edges, (graph[b].edge_count + 1) * sizeof(Edge));
        graph[b].edges[graph[b].edge_count].id = i;
        graph[b].edges[graph[b].edge_count].to = a;
        graph[b].edge_count++;
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

    for (int i = 0; i < n; i++) {
        free(graph[i].edges);
    }

    return 0;
}
