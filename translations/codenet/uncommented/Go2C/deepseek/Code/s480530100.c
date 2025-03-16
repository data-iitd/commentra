#include <stdio.h>
#include <stdlib.h>

// Function to output results
void out(int x, ...) {
    va_list args;
    va_start(args, x);
    for (int i = 0; i < x; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

// Binary Indexed Tree (BIT)
typedef struct {
    int n;
    int *data;
} BIT;

// Function to create a new BIT
BIT* FenwickTree(int n) {
    BIT *ret = (BIT*)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ret->data[i] = 0;
    }
    return ret;
}

// Function to add value x to index p
void BIT_Add(BIT *b, int p, int x) {
    p++;
    while (p <= b->n) {
        b->data[p-1] += x;
        p += p & -p;
    }
}

// Function to get sum of range [l, r)
int BIT_Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

// Helper function to get sum up to index r
int sum(BIT *b, int r) {
    int s = 0;
    while (r > 0) {
        s += b->data[r-1];
        r -= r & -r;
    }
    return s;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    BIT *fw = FenwickTree(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        BIT_Add(fw, i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, x;
            scanf("%d %d", &p, &x);
            BIT_Add(fw, p, x);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            out(1, BIT_Sum(fw, l, r));
        }
    }

    free(fw->data);
    free(fw);
    return 0;
}
