#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define MAXN 500050

typedef struct {
    int idx, l, r;
} Query;

int n, q;
int C[MAXN];
int P[MAXN];
int Answers[MAXN];
Query Q[MAXN];

typedef struct {
    int *dat;
    int n;
} FenwickTree;

FenwickTree* NewFenwickTree(int n) {
    FenwickTree *ft = (FenwickTree *)malloc(sizeof(FenwickTree));
    ft->dat = (int *)calloc(n + 1, sizeof(int));
    ft->n = n;
    return ft;
}

void Add(FenwickTree *ft, int i, int x) {
    while (i <= ft->n) {
        ft->dat[i] += x;
        i += i & (-i);
    }
}

int Sum(FenwickTree *ft, int i) {
    int s = 0;
    while (i > 0) {
        s += ft->dat[i];
        i -= i & (-i);
    }
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
<<<<<<< HEAD
    }

    memset(P, -1, sizeof(P));

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Q[i] = (Query){i, l, r};
=======
        P[i] = -1; // Initialize positions to -1
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].idx = i; // Store the index of the query
>>>>>>> 98c87cb78a (data updated)
    }

    // Sort queries based on the right bound
    qsort(Q, q, sizeof(Query), [](const void *a, const void *b) {
        return ((Query *)a)->r - ((Query *)b)->r;
    });

<<<<<<< HEAD
    FenwickTree *ft = NewFenwickTree(MAXN);
=======
    FenwickTree *ft = NewFenwickTree(n);
>>>>>>> 98c87cb78a (data updated)
    int k = 0;

    for (int i = 0; i < q; i++) {
        while (k < Q[i].r) {
            if (P[C[k]] != -1) {
<<<<<<< HEAD
                Add(ft, P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            Add(ft, k + 1, 1);
=======
                Add(ft, P[C[k]] + 1, -1); // Remove previous occurrence
            }
            P[C[k]] = k; // Update last position
            Add(ft, k + 1, 1); // Add current value
>>>>>>> 98c87cb78a (data updated)
            k++;
        }
        Answers[Q[i].idx] = Sum(ft, Q[i].r) - Sum(ft, Q[i].l - 1);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]);
    }

    free(ft->dat);
    free(ft);
    return 0;
}

/* <END-OF-CODE> */
