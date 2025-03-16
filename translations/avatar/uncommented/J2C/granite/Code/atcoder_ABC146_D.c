
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    int id;
    Edge* edges;
    int edges_size;
} Node;

void dfs(Node* nodes, int n, int to, int color, int parents) {
    int k = 1;
    for (int i = 0; i < nodes[to].edges_size; i++) {
        if (nodes[to].edges[i].to == parents) continue;
        if (k == color) k++;
        nodes[nodes[to].edges[i].to].color = k;
        dfs(nodes, n, nodes[to].edges[i].to, k, to);
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
        nodes[i].edges_size = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        nodes[a].edges[nodes[a].edges_size].id = i;
        nodes[a].edges[nodes[a].edges_size].to = b;
        nodes[a].edges_size++;
        nodes[b].edges[nodes[b].edges_size].id = i;
        nodes[b].edges[nodes[b].edges_size].to = a;
        nodes[b].edges_size++;
    }
    for (int i = 0; i < n; i++) {
        nodes[i].color = -1;
    }
    dfs(nodes, n, 0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        if (max < nodes[i].color) max = nodes[i].color;
    }
    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", nodes[i].color);
    }
    return 0;
}
