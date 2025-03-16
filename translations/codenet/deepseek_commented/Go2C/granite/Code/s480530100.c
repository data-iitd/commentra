
#include <stdio.h>

// out is a helper function to print output.
void out(int x,...) {
    va_list args;
    va_start(args, x);
    vprintf(x, args);
    va_end(args);
}

// main function is the entry point of the program.
int main() {
    // Set the buffer size for the scanner to a large value.
    setvbuf(stdin, NULL, _IONBF, 1000000);

    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    scanf("%d %d", &n, &q);

    // Initialize a Fenwick Tree with n elements.
    int *fw = (int *)malloc(sizeof(int) * n);

    // Read n elements and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        fw[i] += a;
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            // Update the value at position p by adding x to it.
            int p, x;
            scanf("%d %d", &p, &x);
            fw[p] += x;
        } else {
            // Query the sum of elements between indices l and r.
            int l, r;
            scanf("%d %d", &l, &r);
            int sum = 0;
            for (int j = l; j < r; j++) {
                sum += fw[j];
            }
            out("%d\n", sum);
        }
    }

    // Free the memory allocated for the Fenwick Tree.
    free(fw);

    return 0;
}

// Fenwick Tree implementation

// BIT represents the Fenwick Tree data structure.
typedef struct {
    int n;
    int *data;
} BIT;

// FenwickTree initializes and returns a new Fenwick Tree with a given size.
BIT *FenwickTree(int n) {
    BIT *ret = (BIT *)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int *)malloc(sizeof(int) * n);
    return ret;
}

// Add updates the value at position p by adding x to it.
void Add(BIT *b, int p, int x) {
    p++; // Convert to 1-based index
    for (int i = p; i <= b->n; i += i & -i) {
        b->data[i-1] += x;
    }
}

// Sum calculates the sum of elements between indices l and r.
int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

// sum calculates the prefix sum up to index r.
int sum(BIT *b, int r) {
    int s = 0;
    for (int i = r; i > 0; i -= i & -i) {
        s += b->data[i-1];
    }
    return s;
}

// END-OF-CODE