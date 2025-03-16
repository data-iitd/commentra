
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct {
    int deg;
    int id;
} Node;

int N, M;
int *degs;
int *parity;
bool *flag;
int **edges;

int cmp(const void *a, const void *b) {
    Node *na = (Node *)a;
    Node *nb = (Node *)b;
    if (na->deg!= nb->deg) {
        return na->deg - nb->deg;
    }
    return na->id - nb->id;
}

int main() {
    scanf("%d %d", &N, &M);
    edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * N);
        memset(edges[i], 0, sizeof(int) * N);
    }
    degs = (int *)malloc(sizeof(int) * N);
    memset(degs, 0, sizeof(int) * N);
    parity = (int *)malloc(sizeof(int) * N);
    memset(parity, 0, sizeof(int) * N);
    flag = (bool *)malloc(sizeof(bool) * N);
    memset(flag, 0, sizeof(bool) * N);
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
    if (M % 2!= 0) {
        printf("-1\n");
        return 0;
    }
    Node *nodes = (Node *)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        nodes[i].deg = degs[i];
        nodes[i].id = i;
    }
    qsort(nodes, N, sizeof(Node), cmp);
    for (int i = 0; i < N; i++) {
        int u = nodes[i].id;
        if (flag[u]) {
            continue;
        }
        flag[u] = true;
        for (int v = 0; v < N; v++) {
            if (edges[u][v] == 1) {
                edges[u][v] = 0;
                edges[v][u] = 0;
                if (parity[u]!= 0 && v == 0) {
                    printf("%d %d\n", u + 1, v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    printf("%d %d\n", v + 1, u + 1);
                    parity[v] = 1 - parity[v];
                }
                degs[v]--;
                nodes[v].deg--;
            }
        }
    }
    return 0;
}
