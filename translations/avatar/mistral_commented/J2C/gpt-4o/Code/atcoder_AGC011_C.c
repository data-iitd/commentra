#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int *neighbors;
    int count;
} Node;

typedef struct Graph {
    Node *nodes;
    int size;
} Graph;

Graph* createGraph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = n;
    graph->nodes = (Node *)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        graph->nodes[i].neighbors = (int *)malloc(n * sizeof(int));
        graph->nodes[i].count = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->nodes[u].neighbors[graph->nodes[u].count++] = v;
    graph->nodes[v].neighbors[graph->nodes[v].count++] = u;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->nodes[i].neighbors);
    }
    free(graph->nodes);
    free(graph);
}

int dfs(Graph *graph, int a, int c, bool *visited, int *color, long *one, long *bipartite, bool *mujun) {
    if (visited[a]) {
        if (color[a] >= 0 && color[a] != c) {
            *mujun = true;
        }
        return 0;
    }
    visited[a] = true;
    color[a] = c;
    int total = 1;
    for (int i = 0; i < graph->nodes[a].count; i++) {
        total += dfs(graph, graph->nodes[a].neighbors[i], 1 - c, visited, color, one, bipartite, mujun);
    }
    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Graph *graph = createGraph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1);
    }
    
    bool *visited = (bool *)calloc(n, sizeof(bool));
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    
    long one = 0, bipartite = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        count++;
        bool mujun = false;
        int kind = dfs(graph, i, 0, visited, color, &one, &bipartite, &mujun);
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }
    
    long total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;
    
    printf("%ld\n", total);
    
    free(visited);
    free(color);
    freeGraph(graph);
    
    return 0;
}

// <END-OF-CODE>
