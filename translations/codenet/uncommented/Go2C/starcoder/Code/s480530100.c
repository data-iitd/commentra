#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000

typedef struct {
	int n;
	int data[MAX_N];
} BIT;

BIT* FenwickTree(int n) {
	BIT* ret = (BIT*)malloc(sizeof(BIT));
	ret->n = n;
	memset(ret->data, 0, sizeof(int) * n);
	return ret;
}

void Add(BIT* b, int p, int x) {
	p++;
	for ( ; p <= b->n; p += p & -p) {
		b->data[p-1] += x;
	}
}

int Sum(BIT* b, int l, int r) {
	return Sum(b, r) - Sum(b, l);
}

int Sum(BIT* b, int r) {
	int s = 0;
	for ( ; r > 0; r -= r & -r) {
		s += b->data[r-1];
	}
	return s;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	BIT* fw = FenwickTree(n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		Add(fw, i, a);
	}

	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int p, x;
			scanf("%d %d", &p, &x);
			Add(fw, p, x);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", Sum(fw, l, r));
		}
	}
}

// 