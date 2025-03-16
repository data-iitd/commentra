#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A helper function to print output
void out(int x) {
	printf("%d\n", x);
}

// Initialize a scanner for reading input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Initialize a buffer for reading input
char buf[1000000];

// Initialize a scanner for reading input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Initialize a scanner for reading input
char *getString() {
	scanf("%s", buf);
	return buf;
}

// Main function
int main() {
	// Initialize the scanner for reading input
	scanf("%s", buf);

	// Read the number of elements 'n' and the number of queries 'q' from the standard input
	int n, q;
	sscanf(buf, "%d %d", &n, &q);

	// Initialize a Fenwick Tree of size 'n'
	BIT *fw = FenwickTree(n);

	// Iterate through each element and add it to the Fenwick Tree
	for (int i = 0; i < n; i++) {
		// Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
		int a;
		scanf("%d", &a);
		fw->Add(i, a);
	}

	// Iterate through each query
	for (int i = 0; i < q; i++) {
		// Read an integer 't' from the standard input to determine the type of query
		int t;
		scanf("%d", &t);

		// If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
		if (t == 0) {
			int p, x;
			scanf("%d %d", &p, &x);
			fw->Add(p, x);
		} else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
			int l, r;
			scanf("%d %d", &l, &r);
			// Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
			out(fw->Sum(l, r));
		}
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
typedef struct {
	int n;
	int *data;
} BIT;

// FenwickTree :
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n);
	memset(ret->data, 0, sizeof(int) * n);
	return ret;
}

// Add :
void Add(BIT *b, int p, int x) {
	p++;
	for (p <= b->n) {
		b->data[p-1] += x;
		p += p & -p;
	}
}

// Sum :
int Sum(BIT *b, int l, int r) {
	return sum(b, r) - sum(b, l);
}

int sum(BIT *b, int r) {
	int s = 0;
	for (r > 0) {
		s += b->data[r-1];
		r -= r & -r;
	}
	return s;
}

