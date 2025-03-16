
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF_INT64 9223372036854775807
#define INF_INT32 2147483647
#define INF_BIT60 1 << 60
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define ALPHABET_NUM 26
#define MOD 1000000007

typedef struct {
    int idx, l, r;
} Query;

typedef struct {
    int *dat;
    int n;
    int minPow2;
} FenwickTree;

FenwickTree *NewFenwickTree(int n) {
    FenwickTree *ft = (FenwickTree *)malloc(sizeof(FenwickTree));
    ft->dat = (int *)malloc(sizeof(int) * (n + 1));
    ft->n = n;

    ft->minPow2 = 1;
    while (ft->minPow2 << 1 <= n) {
        ft->minPow2 <<= 1;
    }

    return ft;
}

int Sum(FenwickTree *ft, int i) {
    int s = 0;

    for (; i > 0; i -= i & (-i)) {
        s += ft->dat[i];
    }

    return s;
}

void Add(FenwickTree *ft, int i, int x) {
    for (; i <= ft->n; i += i & (-i)) {
        ft->dat[i] += x;
    }
}

int LowerBound(FenwickTree *ft, int w) {
    if (w <= 0) {
        return 0;
    }

    int x = 0;
    for (int k = ft->minPow2; k > 0; k /= 2) {
        if (x + k <= ft->n && ft->dat[x + k] < w) {
            w -= ft->dat[x + k];
            x += k;
        }
    }

    return x + 1;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *C = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    Query *Q = (Query *)malloc(sizeof(Query) * q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].idx = i;
    }

    sort(Q, Q + q, [](Query a, Query b) { return a.r < b.r; });

    int *P = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }

    int *Answers = (int *)malloc(sizeof(int) * q);
    int k = 0;
    for (int i = 0; i < q; i++) {
        while (k < Q[i].r) {
            if (P[C[k]] != -1) {
                Add(NewFenwickTree(500000 + 50), P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            Add(NewFenwickTree(500000 + 50), k + 1, 1);

            k++;
        }
        Answers[Q[i].idx] = Sum(NewFenwickTree(500000 + 50), Q[i].r) - Sum(NewFenwickTree(500000 + 50), Q[i].l - 1);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]);
    }

    return 0;
}

