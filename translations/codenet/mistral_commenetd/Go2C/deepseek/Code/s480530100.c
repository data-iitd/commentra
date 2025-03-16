#include <stdio.h>
#include <stdlib.h>

// A helper function to print output
void out(int x, ...) {
	va_list args;
	va_start(args, x);
	printf("%d\n", x);
	va_end(args);
}

// Function to read an integer from the standard input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a string from the standard input
char* getString() {
	char *str = (char*)malloc(1000001 * sizeof(char));
	scanf("%s", str);
	return str;
}

// BIT :
typedef struct {
	int n;
	int *data;
} BIT;

// FenwickTree :
BIT* FenwickTree(int n) {
	BIT *ret = (BIT*)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ret->data[i] = 0;
	}
	return ret;
}

// Add :
void BIT_Add(BIT *b, int p, int x) {
	p++;
	while (p <= b->n) {
		b->data[p-1] += x;
		p += p & -p;
	}
}

// Sum :
int BIT_Sum(BIT *b, int l, int r) {
	return sum(b, r) - sum(b, l);
}

int sum(BIT *b, int r) {
	int s = 0;
	while (r > 0) {
		s += b->data[r-1];
		r -= r & -r;
	}
	return s;
}

// Main function
int main() {
	// Initialize the scanner for reading input
	// sc.Split(bufio.ScanWords)
	// sc.Buffer([]byte{}, 1000000)

	// Read the number of elements 'n' and the number of queries 'q' from the standard input
	int n = getInt();
	int q = getInt();

	// Initialize a Fenwick Tree of size 'n'
	BIT *fw = FenwickTree(n);

	// Iterate through each element and add it to the Fenwick Tree
	for (int i = 0; i < n; i++) {
		// Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
		int a = getInt();
		BIT_Add(fw, i, a);
	}

	// Iterate through each query
	for (int i = 0; i < q; i++) {
		// Read an integer 't' from the standard input to determine the type of query
		int t = getInt();

		// If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
		if (t == 0) {
			int p = getInt();
			int x = getInt();
			BIT_Add(fw, p, x);
		} else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
			int l = getInt();
			int r = getInt();
			// Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
			out(BIT_Sum(fw, l, r));
		}
	}

	// Free allocated memory
	free(fw->data);
	free(fw);

	return 0;
}
