#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

typedef struct Node {
    Edge* edges;
    int edge_count;
} Node;

Node* g;
int* ans;
int n;

void dfs(int to, int color, int parents) {
    int k = 1;
    for (int i = 0; i < g[to].edge_count; i++) {
        Edge e = g[to].edges[i];
        if (e.to == parents) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(e.to, k, to);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    g = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        g[i].edges = (Edge*)malloc((n - 1) * sizeof(Edge));
        g[i].edge_count = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].edges[g[a].edge_count++] = (Edge){i, b};
        g[b].edges[g[b].edge_count++] = (Edge){i, a};
    }

    ans = (int*)malloc((n - 1) * sizeof(int));
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

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i].edges);
    }
    free(g);
    free(ans);

    return 0;
}

// <END-OF-CODE>
