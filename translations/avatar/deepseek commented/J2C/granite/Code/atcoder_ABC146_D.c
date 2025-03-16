
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    int id;
    Edge* edges;
    int edge_count;
} Node;

void dfs(Node* nodes, int* ans, int n, int to, int color, int parent) {
    int k = 1;
    for (int i = 0; i < nodes[to].edge_count; i++) {
        Edge* e = &nodes[to].edges[i];
        if (e->to == parent) continue;
        if (k == color) k++;
        ans[e->id] = k;
        dfs(nodes, ans, n, e->to, k, to);
        k++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* nodes = (Node*)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].edges = (Edge*)malloc(sizeof(Edge) * (n - 1));
        nodes[i].edge_count = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        Edge* e = &nodes[a].edges[nodes[a].edge_count];
        e->id = i;
        e->to = b;
        nodes[a].edge_count++;
        e = &nodes[b].edges[nodes[b].edge_count];
        e->id = i;
        e->to = a;
        nodes[b].edge_count++;
    }
    int* ans = (int*)malloc(sizeof(int) * (n - 1));
    dfs(nodes, ans, n, 0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        max = ans[i] > max? ans[i] : max;
    }
    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
