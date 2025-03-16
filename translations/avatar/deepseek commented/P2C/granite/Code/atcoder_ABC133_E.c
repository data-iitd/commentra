
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *array[100000];
    int len;
} Graph;

void addEdge(Graph *g, int u, int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->next = g->array[u];
    g->array[u] = n;

    Node *m = (Node *)malloc(sizeof(Node));
    m->val = u;
    m->next = g->array[v];
    g->array[v] = m;
}

void initGraph(Graph *g, int n) {
    int i;
    for (i = 0; i < n; i++) {
        g->array[i] = NULL;
    }
    g->len = n;
}

long long dfs(Graph *g, int fro, int to, int f, int k) {
    long long caseNum = f;
    int colorNum = k - 1;
    if (f == k) {
        colorNum--;
    }
    Node *p = g->array[fro];
    while (p!= NULL) {
        if (p->val == to) {
            p = p->next;
            continue;
        }
        long long pat = dfs(g, p->val, fro, colorNum, k);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = caseNum * pat % 100000007;
        colorNum--;
        p = p->next;
    }
    return caseNum;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Graph g;
    initGraph(&g, n);
    int i;
    for (i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(&g, a - 1, b - 1);
    }
    long long ans = dfs(&g, 0, -1, k, k);
    printf("%lld\n", ans);
    return 0;
}

