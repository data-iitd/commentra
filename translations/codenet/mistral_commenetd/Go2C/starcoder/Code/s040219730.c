#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int n, q;
int C[500000 + 50];

int P[500000 + 50];
int Answers[500000 + 50];

typedef struct {
	int idx, l, r;
} Query;

Query Q[500000 + 50];

int main() {
	scanf("%d%d", &n, &q);
	REP(i, n) scanf("%d", &C[i]);

	REP(i, n) P[i] = -1;

	REP(i, q) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].idx = i;
	}

	// Sort queries by r
	qsort(Q, q, sizeof(Query), (int (*)(const void *, const void *))compare);

	int k = 0;
	FenwickTree *ft = newFenwickTree(500000 + 50);

	for (int i = 0; i < q; i++) {
		// Process each query
		for (int j = k; j < Q[i].r; j++) {
			if (P[C[j]]!= -1) {
				ft->add(P[C[j]] + 1, -1);
			}
			P[C[j]] = j;
			ft->add(j + 1, 1);
		}

		// Calculate answer and print it
		Answers[Q[i].idx] = ft->sum(Q[i].r) - ft->sum(Q[i].l - 1);
	}

	// Print answers
	REP(i, q) {
		printf("%d\n", Answers[i]);
	}

	return 0;
}

// Public methods
// ft := newFenwickTree(200000 + 5);
// s := ft->sum(i); 						// Sum of [1, i](1-based)
// ft->add(i, x); 							// Add x to i(1-based)
// idx := ft->lowerBound(w); 		// minimum idx such that bit.Sum(idx) >= w

typedef struct {
	int *dat;
	int n;
	int minPow2;
} FenwickTree;

// n(>=1) is number of elements of original data
FenwickTree *newFenwickTree(int n) {
	FenwickTree *ft = (FenwickTree *)malloc(sizeof(FenwickTree));

	ft->dat = (int *)malloc((n + 1) * sizeof(int));
	ft->n = n;

	ft->minPow2 = 1;
	while ((ft->minPow2 << 1) <= n) {
		ft->minPow2 <<= 1;
	}

	return ft;
}

// Sum of [1, i](1-based)
int sum(FenwickTree *ft, int i) {
	int s = 0;

	while (i > 0) {
		s += ft->dat[i];
		i -= i & (-i);
	}

	return s;
}

// Add x to i(1-based)
void add(FenwickTree *ft, int i, int x) {
	while (i <= ft->n) {
		ft->dat[i] += x;
		i += i & (-i);
	}
}

// LowerBound returns minimum i such that bit.Sum(i) >= w.
int lowerBound(FenwickTree *ft, int w) {
	if (w <= 0) {
		return 0;
	}

	int x = 0;
	for (int k = ft->minPow2; k > 0; k >>= 1) {
		if (x + k <= ft->n && ft->dat[x + k] < w) {
			w -= ft->dat[x + k];
			x += k;
		}
	}

	return x + 1;
}

int compare(const void *a, const void *b) {
	Query *q1 = (Query *)a;
	Query *q2 = (Query *)b;

	if (q1->r < q2->r) {
		return -1;
	} else if (q1->r > q2->r) {
		return 1;
	} else {
		return 0;
	}
}

