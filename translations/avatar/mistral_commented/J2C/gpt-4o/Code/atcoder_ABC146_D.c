#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Graph {
    Edge* edges;
    int edgeCount;
} Graph;

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(n * sizeof(Graph));
    for (int i = 0; i < n; i++) {
        g[i].edges = NULL;
        g[i].edgeCount = 0;
    }
    return g;
}

void addEdge(Graph* g, int a, int b, int id) {
    g[a].edges = (Edge*)realloc(g[a].edges, (g[a].edgeCount + 1) * sizeof(Edge));
    g[a].edges[g[a].edgeCount++] = (Edge){id, b};

    g[b].edges = (Edge*)realloc(g[b].edges, (g[b].edgeCount + 1) * sizeof(Edge));
    g[b].edges[g[b].edgeCount++] = (Edge){id, a};
}

void dfs(Graph* g, int to, int color, int parents, int* ans, int* maxColor) {
    int k = 1;
    for (int i = 0; i < g[to].edgeCount; i++) {
        Edge e = g[to].edges[i];
        if (e.to == parents) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(g, e.to, k, to, ans, maxColor);
        k++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    Graph* g = createGraph(n);
    int* ans = (int*)malloc((n - 1) * sizeof(int));
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(g, a - 1, b - 1, i);
    }

    int maxColor = 0;
    dfs(g, 0, -1, -1, ans, &maxColor);

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

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i].edges);
    }
    free(g);
    free(ans);

    return 0;
}

// <END-OF-CODE>
