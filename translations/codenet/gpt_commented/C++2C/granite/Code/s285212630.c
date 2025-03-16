
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int to;
    long long cost;
} Edge;

typedef struct {
    Edge *es;
    int size;
} Graph;

typedef struct {
    int parent;
    int depth;
    long long dist;
} Node;

typedef struct {
    Node *nodes;
    int size;
} Tree;

void initTree(Tree *tree, int n) {
    tree->nodes = (Node*)malloc(sizeof(Node) * n);
    tree->size = n;
    for (int i = 0; i < n; i++) {
        tree->nodes[i].parent = -1;
        tree->nodes[i].depth = 0;
        tree->nodes[i].dist = 0;
    }
}

void dfs(Tree *tree, int v, int p, int d, long long c) {
    tree->nodes[v].parent = p;
    tree->nodes[v].depth = d;
    tree->nodes[v].dist = c;
    for (int i = 0; i < tree->nodes[v].size; i++) {
        Edge e = tree->nodes[v].es[i];
        if (e.to!= p) {
            dfs(tree, e.to, v, d + 1, c + e.cost);
        }
    }
}

void initLCA(Tree *tree) {
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
        for (int v = 0; v < tree->size; v++) {
            if (tree->nodes[v].parent == -1) {
                tree->nodes[v].parent = -1;
            } else {
                tree->nodes[v].parent = tree->nodes[tree->nodes[v].parent].parent;
            }
        }
    }
}

int lca(Tree *tree, int u, int v) {
    tree->nodes[u].depth > tree->nodes[v].depth? u = walk(tree, u, tree->nodes[u].depth - tree->nodes[v].depth) : v = walk(tree, v, tree->nodes[v].depth - tree->nodes[u].depth);
    if (u == v) return u;
    for (int k = tree->size; k >= 0; k--) {
        if (tree->nodes[u].parent!= tree->nodes[v].parent) {
            u = tree->nodes[u].parent;
            v = tree->nodes[v].parent;
        }
    }
    return tree->nodes[u].parent;
}

int walk(Tree *tree, int v, int k) {
    for (int i = 0; i < MAX_LOG_V; i++) {
        if ((k >> i) & 1) {
            v = tree->nodes[v].parent;
        }
    }
    return v;
}

long long dist(Tree *tree, int u, int v) {
    int l = lca(tree, u, v);
    return tree->nodes[u].dist + tree->nodes[v].dist - 2 * tree->nodes[l].dist;
}

int main() {
    int n, q, k;
    scanf("%d", &n);
    Tree tree;
    initTree(&tree, n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);
        a--;
        b--;
        Edge e1 = {b, c};
        Edge e2 = {a, c};
        tree.nodes[a].es = (Edge*)malloc(sizeof(Edge));
        tree.nodes[a].es[0] = e1;
        tree.nodes[a].size++;
        tree.nodes[b].es = (Edge*)malloc(sizeof(Edge));
        tree.nodes[b].es[0] = e2;
        tree.nodes[b].size++;
    }
    dfs(&tree, 0, -1, 0, 0);
    initLCA(&tree);
    scanf("%d %d", &q, &k);
    k--;
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        printf("%lld\n", dist(&tree, x, k) + dist(&tree, k, y));
    }
    return 0;
}

