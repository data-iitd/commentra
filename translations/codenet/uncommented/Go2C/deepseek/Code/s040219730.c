#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1152921504606846976
#define INF_INT32 2147483647
#define INF_BIT30 1073741823
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    int idx, l, r;
} Query;

int n, q;
int C[500000 + 50];
Query Q[500000 + 50];

int P[500000 + 50];
int Answers[500000 + 50];

void init() {
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }
}

typedef struct {
    int *dat;
    int n;
    int minPow2;
} FenwickTree;

FenwickTree* newFenwickTree(int n) {
    FenwickTree *ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->dat = (int*)calloc(n + 1, sizeof(int));
    ft->n = n;
    ft->minPow2 = 1;
    while ((ft->minPow2 << 1) <= n) {
        ft->minPow2 <<= 1;
    }
    return ft;
}

int sum(FenwickTree *ft, int i) {
    int s = 0;
    while (i > 0) {
        s += ft->dat[i];
        i -= i & (-i);
    }
    return s;
}

void add(FenwickTree *ft, int i, int x) {
    while (i <= ft->n) {
        ft->dat[i] += x;
        i += i & (-i);
    }
}

int lowerBound(FenwickTree *ft, int w) {
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

void main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Q[i].idx = i;
        Q[i].l = l;
        Q[i].r = r;
    }

    init();
    FenwickTree *ft = newFenwickTree(500000 + 50);

    int k = 0;
    for (int i = 0; i < q; i++) {
        while (k < Q[i].r) {
            if (P[C[k]] != -1) {
                add(ft, P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            add(ft, k + 1, 1);
            k++;
        }
        Answers[Q[i].idx] = sum(ft, Q[i].r) - sum(ft, Q[i].l - 1);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]);
    }
}

