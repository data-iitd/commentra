
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
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
    }
    return x->idx - y->idx;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    assert(1 <= N && N <= 100000);
    assert(0 <= M && M <= 100000);

    int **edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * N);
        memset(edges[i], 0, sizeof(int) * N);
    }

    int *degs = (int *)malloc(sizeof(int) * N);
    memset(degs, 0, sizeof(int) * N);

    int *parity = (int *)malloc(sizeof(int) * N);
    memset(parity, 0, sizeof(int) * N);

    bool *flag = (bool *)malloc(sizeof(bool) * N);
    memset(flag, false, sizeof(bool) * N);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(1 <= a && a <= N);
        assert(1 <= b && b <= N);
        edges[a - 1][b - 1] = 1;
        edges[b - 1][a - 1] = 1;
        degs[a - 1]++;
        degs[b - 1]++;
    }

    if (M % 2!= 0) {
        printf("-1\n");
        return 0;
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
                edges[u][v] = edges[v][u] = 0;
                if (parity[u]!= 0 && v == 0) {
                    printf("%d %d\n", u + 1, v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    printf("%d %d\n", v + 1, u + 1);
                    parity[v] = 1 - parity[v];
                }
                degs[v]--;
                Q[i].deg = degs[v];
                qsort(Q, N, sizeof(Node), cmp);
            }
        }
    }

    return 0;
}
