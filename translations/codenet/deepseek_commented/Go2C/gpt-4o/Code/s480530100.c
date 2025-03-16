#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *data;
} BIT;

// Function to create a new Fenwick Tree
BIT* FenwickTree(int n) {
    BIT *tree = (BIT *)malloc(sizeof(BIT));
    tree->n = n;
    tree->data = (int *)calloc(n, sizeof(int));
    return tree;
}

// Function to update the value at position p by adding x
void Add(BIT *b, int p, int x) {
    p++; // Convert to 1-based index
    while (p <= b->n) {
        b->data[p - 1] += x;
        p += p & -p; // Move to the next node
    }
}

// Function to calculate the prefix sum up to index r
int sum(BIT *b, int r) {
    int s = 0;
    while (r > 0) {
        s += b->data[r - 1];
        r -= r & -r; // Move to the parent node
    }
    return s;
}

// Function to calculate the sum of elements between indices l and r
int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    BIT *fw = FenwickTree(n);

    // Read n elements and add them to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        Add(fw, i, a);
    }

    // Process q queries
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            // Update the value at position p by adding x to it
            int p, x;
            scanf("%d %d", &p, &x);
            Add(fw, p, x);
        } else {
            // Query the sum of elements between indices l and r
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", Sum(fw, l, r));
        }
    }

    // Free allocated memory
    free(fw->data);
    free(fw);

    return 0;
}

// <END-OF-CODE>
