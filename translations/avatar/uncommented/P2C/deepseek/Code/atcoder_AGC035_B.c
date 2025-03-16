#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100000

typedef struct {
    int deg;
    int node;
} HeapNode;

typedef struct {
    HeapNode data[MAXN];
    int size;
} MinHeap;

void heapInit(MinHeap *h) {
    h->size = 0;
}

void heapPush(MinHeap *h, HeapNode x) {
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].deg <= x.deg) break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i] = x;
}

HeapNode heapPop(MinHeap *h) {
    HeapNode ret = h->data[0];
    HeapNode x = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int l = 2 * i + 1, r = 2 * i + 2;
        int c = (r < h->size && h->data[r].deg < h->data[l].deg) ? r : l;
        if (h->data[c].deg >= x.deg) break;
        h->data[i] = h->data[c];
        i = c;
    }
    h->data[i] = x;
    return ret;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int edges[N][N];
    int degs[N];
    int parity[N];
    bool flag[N];

    for (int i = 0; i < N; i++) {
        degs[i] = 0;
        parity[i] = 0;
        flag[i] = false;
        for (int j = 0; j < N; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        edges[a][degs[a]++] = b;
        edges[b][degs[b]++] = a;
    }

    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    MinHeap Q;
    heapInit(&Q);
    for (int i = 0; i < N; i++) {
        heapPush(&Q, (HeapNode){degs[i], i});
    }

    while (Q.size > 0) {
        HeapNode u = heapPop(&Q);
        if (flag[u.node]) continue;
        flag[u.node] = true;

        for (int i = 0; i < degs[u.node]; i++) {
            int v = edges[u.node][i];
            edges[v][--degs[v]] = 0;
            if (parity[u.node] != 0 && i == 0) {
                printf("%d %d\n", u.node + 1, v + 1);
                parity[u.node] = 1 - parity[u.node];
            } else {
                printf("%d %d\n", v + 1, u.node + 1);
                parity[v] = 1 - parity[v];
            }
            heapPush(&Q, (HeapNode){degs[v], v});
        }
    }

    return 0;
}
