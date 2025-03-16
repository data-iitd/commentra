#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct Edge {
    int id;
    int to;
    struct Edge* next;
} Edge;

typedef struct List {
    Edge* head;
} List;

List g[MAXN];
int ans[MAXN];
int n;

void dfs(int to, int color, int parent) {
    int k = 1;
    Edge* e = g[to].head;
    while (e != NULL) {
        if (e->to != parent) {
            if (k == color) k++;
            ans[e->id] = k;
            dfs(e->to, k, to);
            k++;
        }
        e = e->next;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        g[i].head = NULL;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        Edge* edgeA = (Edge*)malloc(sizeof(Edge));
        edgeA->id = i;
        edgeA->to = b;
        edgeA->next = g[a].head;
        g[a].head = edgeA;

        Edge* edgeB = (Edge*)malloc(sizeof(Edge));
        edgeB->id = i;
        edgeB->to = a;
        edgeB->next = g[b].head;
        g[b].head = edgeB;
    }
    memset(ans, 0, sizeof(ans));
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
