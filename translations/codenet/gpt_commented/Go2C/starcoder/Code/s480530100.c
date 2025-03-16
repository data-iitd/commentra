

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
	int n; // Number of elements in the tree
	int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT *b, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (p <= b->n) {
		b->data[p-1] += x; // Update the tree data
		p += p & -p; // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT *b, int l, int r) {
	return Sum(b, r) - Sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT *b, int r) {
	int s = 0; // Initialize sum
	for (r > 0) {
		s += b->data[r-1]; // Add the value at index r-1
		r -= r & -r; // Move to the parent index
	}
	return s; // Return the calculated sum
}

// ** copy to here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// main function
int main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	scanf("%d %d", &n, &q);
	scanf("%s", buf);
	scanf("%s", buf);

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	BIT *fw = FenwickTree(n);

	// Read n integers and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a = atoi(buf);
		Add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t = atoi(buf); // Read the type of query.
		if (t == 0) {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			scanf("%d %d", &p, &x);
			Add(fw, p, x);
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			scanf("%d %d", &l, &r);
			printf("%d\n", Sum(fw, l, r));
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
	int n; // Number of elements in the tree
	int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT *b, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (p <= b->n) {
		b->data[p-1] += x; // Update the tree data
		p += p & -p; // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT *b, int l, int r) {
	return Sum(b, r) - Sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT *b, int r) {
	int s = 0; // Initialize sum
	for (r > 0) {
		s += b->data[r-1]; // Add the value at index r-1
		r -= r & -r; // Move to the parent index
	}
	return s; // Return the calculated sum
}

// ** copy to here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// main function
int main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	scanf("%d %d", &n, &q);
	scanf("%s", buf);
	scanf("%s", buf);

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	BIT *fw = FenwickTree(n);

	// Read n integers and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a = atoi(buf);
		Add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t = atoi(buf); // Read the type of query.
		if (t == 0) {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			scanf("%d %d", &p, &x);
			Add(fw, p, x);
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			scanf("%d %d", &l, &r);
			printf("%d\n", Sum(fw, l, r));
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
	int n; // Number of elements in the tree
	int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT *b, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (p <= b->n) {
		b->data[p-1] += x; // Update the tree data
		p += p & -p; // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT *b, int l, int r) {
	return Sum(b, r) - Sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT *b, int r) {
	int s = 0; // Initialize sum
	for (r > 0) {
		s += b->data[r-1]; // Add the value at index r-1
		r -= r & -r; // Move to the parent index
	}
	return s; // Return the calculated sum
}

// ** copy to here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// main function
int main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	scanf("%d %d", &n, &q);
	scanf("%s", buf);
	scanf("%s", buf);

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	BIT *fw = FenwickTree(n);

	// Read n integers and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a = atoi(buf);
		Add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t = atoi(buf); // Read the type of query.
		if (t == 0) {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			scanf("%d %d", &p, &x);
			Add(fw, p, x);
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			scanf("%d %d", &l, &r);
			printf("%d\n", Sum(fw, l, r));
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
	int n; // Number of elements in the tree
	int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT *b, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (p <= b->n) {
		b->data[p-1] += x; // Update the tree data
		p += p & -p; // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT *b, int l, int r) {
	return Sum(b, r) - Sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT *b, int r) {
	int s = 0; // Initialize sum
	for (r > 0) {
		s += b->data[r-1]; // Add the value at index r-1
		r -= r & -r; // Move to the parent index
	}
	return s; // Return the calculated sum
}

// ** copy to here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// main function
int main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	scanf("%d %d", &n, &q);
	scanf("%s", buf);
	scanf("%s", buf);

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	BIT *fw = FenwickTree(n);

	// Read n integers and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a = atoi(buf);
		Add(fw, i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t = atoi(buf); // Read the type of query.
		if (t == 0) {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			scanf("%d %d", &p, &x);
			Add(fw, p, x);
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			scanf("%d %d", &l, &r);
			printf("%d\n", Sum(fw, l, r));
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
	int n; // Number of elements in the tree
	int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT *FenwickTree(int n) {
	BIT *ret = (BIT *)malloc(sizeof(BIT));
	ret->n = n;
	ret->data = (int *)malloc(sizeof(int) * n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT *b, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (p <= b->n) {
		b->data[p-1] += x; // Update the tree data
		p += p & -p; // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT *b, int l, int r) {
	return Sum(b, r) - Sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT *b, int r) {
	int s = 0; // Initialize sum
	for (r > 0) {
		s += b->data[r-1]; // Add the value at index r-1
		r -= r & -r; // Move to the parent index
	}
	return s; // Return the calculated sum
}

// ** copy to here to your source code **
//
// fenwick tree
//  1. go lang ha