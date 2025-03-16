
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000

typedef struct {
    int to;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Graph;

void addEdge(Graph *g, int from, int to) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->to = to;
    n->next = g[from].head;
    g[from].head = n;
}

void dfs(Graph *g, int v, int p, int k, int *h, int *c) {
    int max_h = 0, max_c = 0;
    Node *cur = g[v].head;
    while (cur!= NULL) {
        int u = cur->to;
        if (u == p) {
            cur = cur->next;
            continue;
        }
        dfs(g, u, v, k, h, c);
        max_h = (*h)[u] > max_h? (*h)[u] : max_h;
        max_c += (*c)[u];
        cur = cur->next;
    }
    (*h)[v] = max_h + 1;
    if ((*h)[v] == k && p!= 0) {
        (*h)[v] = 0;
        max_c++;
    }
    (*c)[v] = max_c;
}

int main() {
    int n, k, a;
    scanf("%d %d", &n, &k);
    Graph g[MAX_N];
    for (int i = 0; i < n; i++) {
        g[i].head = NULL;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        addEdge(&g[i], a - 1, i);
        addEdge(&g[a - 1], i, a - 1);
    }
    int h[MAX_N], c[MAX_N];
    for (int i = 0; i < n; i++) {
        h[i] = 0;
        c[i] = 0;
    }
    dfs(&g, 0, -1, k, &h, &c);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i];
    }
    if (a!= 1) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
