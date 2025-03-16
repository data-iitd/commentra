
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int deg;
    int idx;
} Node;

int cmp(const void *a, const void *b) {
    Node *x = (Node *)a;
    Node *y = (Node *)b;
    if (x->deg!= y->deg) {
        return x->deg - y->deg;
    } else {
        return x->idx - y->idx;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if (M % 2!= 0) {
        printf("-1\n");
        return 0;
    }
    int *edges[N];
    int degs[N];
    int parity[N];
    bool flag[N];
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * N);
        memset(edges[i], 0, sizeof(int) * N);
        degs[i] = 0;
        parity[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][b] = 1;
        edges[b][a] = 1;
        degs[a]++;
        degs[b]++;
    }
    Node *Q = (Node *)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        Q[i].deg = degs[i];
        Q[i].idx = i;
    }
    qsort(Q, N, sizeof(Node), cmp);
    for (int i = 0; i < N; i++) {
        int u = Q[i].idx;
        if (flag[u]) {
            continue;
        }
        flag[u] = true;
        for (int v = 0; v < N; v++) {
            if (edges[u][v] == 1) {
                edges[u][v] = 0;
                edges[v][u] = 0;
                if (parity[u] == 0) {
                    printf("%d %d\n", u + 1, v + 1);
                    parity[u] = 1;
                } else {
                    printf("%d %d\n", v + 1, u + 1);
                    parity[v] = 1;
                }
                degs[v]--;
                Q[i].deg = degs[v];
                qsort(Q, N, sizeof(Node), cmp);
            }
        }
    }
    return 0;
}

