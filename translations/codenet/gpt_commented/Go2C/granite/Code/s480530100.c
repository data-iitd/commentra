
#include <stdio.h>

// out is a utility function to print output to the console.
void out(int x,...) {
    va_list args;
    va_start(args, x);
    vprintf(x, args);
    va_end(args);
}

// Initialize a new scanner to read input from standard input.
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// getString reads a string from input and returns it.
char* getString() {
    char buf[1000000];
    fgets(buf, sizeof(buf), stdin);
    return buf;
}

int main() {
    // Set the scanner to split input by whitespace and allocate a large buffer.
    setbuf(stdin, NULL);

    // Read the number of elements (n) and the number of queries (q).
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    int fw[n];
    for (int i = 0; i < n; i++) {
        fw[i] = 0; // Initialize all elements to 0
    }

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a = getInt();
        for (int x = i; x < n; x |= x + 1) {
            fw[x] += a; // Update the Fenwick Tree
        }
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt(); // Read the type of query.
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p = getInt(), x = getInt();
            for (int j = p; j < n; j |= j + 1) {
                fw[j] += x; // Update the Fenwick Tree
            }
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l = getInt(), r = getInt();
            int sum = 0;
            for (int j = r - 1; j >= 0; j = (j & (j + 1)) - 1) {
                sum += fw[j]; // Calculate the sum
            }
            for (int j = l - 1; j >= 0; j = (j & (j + 1)) - 1) {
                sum -= fw[j]; // Subtract the sum of the range [0, l)
            }
            out("%d\n", sum); // Output the sum
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

// BIT represents a Binary Indexed Tree (Fenwick Tree).
typedef struct {
    int n; // Number of elements in the tree
    int *data; // Array to store the tree data
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT* FenwickTree(int n) {
    BIT *ret = (BIT*)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int*)malloc(sizeof(int) * n); // Create a slice to hold the tree data
    return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void FenwickTreeAdd(BIT *b, int p, int x) {
    p++; // Increment p to match the 1-based index used in Fenwick Tree
    for (int i = p; i <= b->n; i |= i + 1) {
        b->data[i-1] += x; // Update the tree data
    }
}

// Sum calculates the sum of elements in the range [l, r).
int FenwickTreeSum(BIT *b, int l, int r) {
    return FenwickTreeSumRange(b, r) - FenwickTreeSumRange(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int FenwickTreeSumRange(BIT *b, int r) {
    int s = 0; // Initialize sum
    for (int i = r; i > 0; i -= i & -i) {
        s += b->data[i-1]; // Add the value at index i-1
    }
    return s; // Return the calculated sum
}

// END-OF-CODE
