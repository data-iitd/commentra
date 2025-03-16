
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define INF 1000000000
#define INF_BIT 1000000000
#define INF_INT 1000000000
#define INF_BIT30 1000000000
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_N 500000 + 50
#define MAX_Q 500000 + 50

typedef struct {
    int idx, l, r;
} Query;

int n, q;
int C[MAX_N];
Query Q[MAX_Q];

int P[MAX_N];
int Answers[MAX_Q];

void init() {
    // Read input
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize P array and Fenwick Tree
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Query query = {idx: i, l: l, r: r};
        Q[i] = query;
    }

    sort(Q, Q + q, cmp);
    FenwickTree ft = NewFenwickTree(500000 + 50);

    int k = 0;
    for (int i = 0; i < q; i++) {
        // Process each query
        while (k < Q[i].r) {
            if (P[C[k]] != -1) {
                ft.Add(P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            ft.Add(k + 1, 1);

            k++;
        }

        // Calculate answer and print it
        Answers[Q[i].idx] = ft.Sum(Q[i].r) - ft.Sum(Q[i].l - 1);
    }

    // Print answers
    for (int i = 0; i < q; i++) {
        // printf("%d\n", Answers[i]);
        printf("%d\n", Answers[i]);
    }
}

// Public methods
// ft := NewFenwickTree(200000 + 5)
// s := ft.Sum(i) 						// Sum of [1, i](1-based)
// ft.Add(i, x) 							// Add x to i(1-based)
// idx := ft.LowerBound(w) 		// minimum idx such that bit.Sum(idx) >= w

typedef struct {
    int *dat;
    int n;
    int minPow2;
} FenwickTree;

// n(>=1) is number of elements of original data
FenwickTree NewFenwickTree(int n) {
    FenwickTree ft;

    ft.dat = (int *)malloc(sizeof(int) * (n + 1));
    ft.n = n;

    ft.minPow2 = 1;
    while (ft.minPow2 << 1 <= n) {
        ft.minPow2 <<= 1;
    }

    return ft;
}

// Sum of [1, i](1-based)
int Sum(FenwickTree ft, int i) {
    int s = 0;

    for (int i = i; i > 0; i -= i & (-i)) {
        s += ft.dat[i];
    }

    return s;
}

// Add x to i(1-based)
void Add(FenwickTree ft, int i, int x) {
    for (int i = i; i <= ft.n; i += i & (-i)) {
        ft.dat[i] += x;
    }
}

// LowerBound returns minimum i such that bit.Sum(i) >= w.
int LowerBound(FenwickTree ft, int w) {
    if (w <= 0) {
        return 0;
    }

    int x = 0;
    for (int k = ft.minPow2; k > 0; k /= 2) {
        if (x + k <= ft.n && ft.dat[x + k] < w) {
            w -= ft.dat[x + k];
            x += k;
        }
    }

    return x + 1;
}

int cmp(const void *a, const void *b) {
    Query *A = (Query *)a;
    Query *B = (Query *)b;

    return A->r < B->r;
}

int main() {
    init();
    return 0;
}

