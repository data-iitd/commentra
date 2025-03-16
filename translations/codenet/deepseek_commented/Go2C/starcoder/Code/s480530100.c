#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// out is a helper function to print output.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads a single word from the input and converts it to an integer.
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// getString reads a single word from the input and returns it as a string.
char* getString() {
	char* s = malloc(1000000);
	scanf("%s", s);
	return s;
}

// main function is the entry point of the program.
int main() {
	// Set the buffer size for the scanner to a large value.
	setbuf(stdin, NULL);

	// Read the number of elements (n) and the number of queries (q).
	int n = getInt();
	int q = getInt();

	// Initialize a Fenwick Tree with n elements.
	BIT* fw = newBIT(n);

	// Read n elements and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a = getInt();
		add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t = getInt();
		if (t == 0) {
			// Update the value at position p by adding x to it.
			int p = getInt();
			int x = getInt();
			add(fw, p, x);
		} else {
			// Query the sum of elements between indices l and r.
			int l = getInt();
			int r = getInt();
			out(sum(fw, r) - sum(fw, l));
		}
	}
}

// BIT implementation

// BIT represents the Fenwick Tree data structure.
typedef struct BIT {
	int n;
	int* data;
} BIT;

// newBIT initializes and returns a new Fenwick Tree with a given size.
BIT* newBIT(int n) {
	BIT* ret = malloc(sizeof(BIT));
	ret->n = n;
	ret->data = malloc(n * sizeof(int));
	memset(ret->data, 0, n * sizeof(int));
	return ret;
}

// add updates the value at position p by adding x to it.
void add(BIT* b, int p, int x) {
	p++; // Convert to 1-based index
	for (int i = p; i <= b->n; i += i & -i) {
		b->data[i-1] += x;
	}
}

// sum calculates the prefix sum up to index r.
int sum(BIT* b, int r) {
	int s = 0;
	for (int i = r; i > 0; i -= i & -i) {
		s += b->data[i-1];
	}
	return s;
}

