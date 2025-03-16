#include <stdio.h>
#include <stdlib.h>

// out is a utility function to print output to the console.
void out(int x, ...) {
    va_list args;
    va_start(args, x);
    printf("%d\n", x);
    va_end(args);
}

// getInt reads an integer from input and returns it.
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// getString reads a string from input and returns it.
char* getString() {
    char *str = (char*)malloc(1000001 * sizeof(char));
    scanf("%s", str);
    return str;
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
    int n;
    int *data;
} BIT;

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT* FenwickTree(int n) {
    BIT *ret = (BIT*)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int*)calloc(n, sizeof(int));
    return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void BIT_Add(BIT *b, int p, int x) {
    p++; // Increment p to match the 1-based index used in Fenwick Tree
    while (p <= b->n) {
        b->data[p-1] += x; // Update the tree data
        p += p & -p; // Move to the next index
    }
}

// Sum calculates the sum of elements in the range [l, r).
int BIT_Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int sum(BIT *b, int r) {
    int s = 0; // Initialize sum
    while (r > 0) {
        s += b->data[r-1]; // Add the value at index r-1
        r -= r & -r; // Move to the parent index
    }
    return s; // Return the calculated sum
}

// Main function
int main() {
    // Read the number of elements (n) and the number of queries (q).
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT *fw = FenwickTree(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a = getInt();
        BIT_Add(fw, i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt(); // Read the type of query.
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p = getInt();
            int x = getInt();
            BIT_Add(fw, p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l = getInt();
            int r = getInt();
            out(BIT_Sum(fw, l, r));
        }
    }

    // Free allocated memory
    free(fw->data);
    free(fw);

    return 0;
}
