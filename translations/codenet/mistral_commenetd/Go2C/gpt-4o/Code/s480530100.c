#include <stdio.h>
#include <stdlib.h>

// A helper function to print output
void out(int x) {
    printf("%d\n", x);
}

// Structure for Fenwick Tree
typedef struct {
    int n;
    int *data;
} BIT;

// Function to create a Fenwick Tree
BIT* FenwickTree(int n) {
    BIT *ret = (BIT *)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int *)calloc(n, sizeof(int));
    return ret;
}

// Function to add a value to the Fenwick Tree
void Add(BIT *b, int p, int x) {
    p++;
    while (p <= b->n) {
        b->data[p - 1] += x;
        p += p & -p;
    }
}

// Function to calculate the sum in the range [0, r)
int sum(BIT *b, int r) {
    int s = 0;
    while (r > 0) {
        s += b->data[r - 1];
        r -= r & -r;
    }
    return s;
}

// Function to calculate the sum in the range [l, r)
int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

int main() {
    int n, q;
    // Read the number of elements 'n' and the number of queries 'q'
    scanf("%d %d", &n, &q);

    // Initialize a Fenwick Tree of size 'n'
    BIT *fw = FenwickTree(n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        Add(fw, i, a);
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);

        // If the query is of type 0
        if (t == 0) {
            int p, x;
            scanf("%d %d", &p, &x);
            Add(fw, p, x);
        } else { // If the query is of type 1
            int l, r;
            scanf("%d %d", &l, &r);
            // Print the sum of elements in the range [l, r]
            out(Sum(fw, l, r));
        }
    }

    // Free allocated memory
    free(fw->data);
    free(fw);

    return 0;
}

// <END-OF-CODE>
