
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_N 500000
#define MAX_Q 500000

typedef struct {
	int idx, l, r;
} Query;

int n, q;
int C[MAX_N + 10];
Query Q[MAX_Q + 10];

int P[MAX_N + 10];
int Answers[MAX_Q + 10];

int main() {
	scanf("%d %d", &n, &q);
	REP(i, n) scanf("%d", &C[i]);

	REP(i, q) {
		scanf("%d %d", &Q[i].l, &Q[i].r);
		Q[i].idx = i;
	}

	int k = 0;
	sort(Q, Q + q, [](Query a, Query b) { return a.r < b.r; });

	FenwickTree ft = newFenwickTree(MAX_N + 10);

	for (int i = 0; i < q; i++) {
		while (k < Q[i].r) {
			if (P[C[k]]!= -1) ft.add(P[C[k]] + 1, -1);
			P[C[k]] = k;
			ft.add(k + 1, 1);

			k++;
		}

		Answers[Q[i].idx] = ft.sum(Q[i].r) - ft.sum(Q[i].l - 1);
	}

	REP(i, q) printf("%d\n", Answers[i]);

	return 0;
}

// Public methods for FenwickTree
// ft := newFenwickTree(200000 + 5);
// s := ft.sum(i); 						// Sum of [1, i] (1-based)
// ft.add(i, x); 							// Add x to i (1-based)
// idx := ft.lowerBound(w); 		// minimum idx such that bit.Sum(idx) >= w

// FenwickTree struct represents a Fenwick Tree
typedef struct {
	int dat[MAX_N + 10];
	int n;
	int minPow2;
} FenwickTree;

// Initializes a new Fenwick Tree with n elements
FenwickTree* newFenwickTree(int n) {
	FenwickTree* ft = (FenwickTree*)malloc(sizeof(FenwickTree));

	ft->dat = (int*)malloc(sizeof(int) * (n + 1));
	ft->n = n;

	ft->minPow2 = 1;
	while ((ft->minPow2 << 1) <= n) ft->minPow2 <<= 1;

	return ft;
}

// Sum of [1, i](1-based)
int sum(FenwickTree* ft, int i) {
	int s = 0;

	while (i > 0) {
		s += ft->dat[i];
		i -= i & (-i);
	}

	return s;
}

// Add x to i(1-based)
void add(FenwickTree* ft, int i, int x) {
	while (i <= ft->n) {
		ft->dat[i] += x;
		i += i & (-i);
	}
}

// LowerBound returns minimum i such that bit.Sum(i) >= w.
int lowerBound(FenwickTree* ft, int w) {
	if (w <= 0) return 0;

	int x = 0;
	for (int k = ft->minPow2; k > 0; k >>= 1) {
		if (x + k <= ft->n && ft->dat[x + k] < w) {
			w -= ft->dat[x + k];
			x += k;
		}
	}

	return x + 1;
}

