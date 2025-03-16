#include <stdio.h>
#include <stdlib.h>

// out is a helper function to print output.
void out(int x, ...) {
	va_list args;
	va_start(args, x);
	printf("%d\n", x);
	va_end(args);
}

// Fenwick Tree implementation

// BIT represents the Fenwick Tree data structure.
typedef struct {
	int n;
	int *data;
} BIT;

// FenwickTree initializes and returns a new Fenwick Tree with a given size.
BIT* FenwickTree(int n) {
	BIT *ret = (BIT*)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int*)calloc(n, sizeof(int));
	return ret;
}

// Add updates the value at position p by adding x to it.
void BIT_Add(BIT *b, int p, int x) {
	p++; // Convert to 1-based index
	while (p <= b->n) {
		b->data[p-1] += x;
		p += p & -p; // Move to the next node
	}
}

// Sum calculates the sum of elements between indices l and r.
int BIT_Sum(BIT *b, int l, int r) {
	return sum(b, r) - sum(b, l);
}

// sum calculates the prefix sum up to index r.
int sum(BIT *b, int r) {
	int s = 0;
	while (r > 0) {
		s += b->data[r-1];
		r -= r & -r; // Move to the parent node
	}
	return s;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	// Initialize a Fenwick Tree with n elements.
	BIT *fw = FenwickTree(n);

	// Read n elements and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		BIT_Add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			// Update the value at position p by adding x to it.
			int p, x;
			scanf("%d %d", &p, &x);
			BIT_Add(fw, p, x);
		} else {
			// Query the sum of elements between indices l and r.
			int l, r;
			scanf("%d %d", &l, &r);
			out(BIT_Sum(fw, l, r));
		}
	}

	// Free the allocated memory
	free(fw->data);
	free(fw);

	return 0;
}
