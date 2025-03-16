#include <stdio.h>
#include <stdlib.h>

void out(int x) {
    printf("%d\n", x);
}

typedef struct {
    int n;
    int *data;
} BIT;

BIT* FenwickTree(int n) {
    BIT *ret = (BIT *)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int *)calloc(n, sizeof(int));
    return ret;
}

void Add(BIT *b, int p, int x) {
    p++;
    while (p <= b->n) {
        b->data[p - 1] += x;
        p += p & -p;
    }
}

int sum(BIT *b, int r) {
    int s = 0;
    while (r > 0) {
        s += b->data[r - 1];
        r -= r & -r;
    }
    return s;
}

int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    BIT *fw = FenwickTree(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        Add(fw, i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, x;
            scanf("%d %d", &p, &x);
            Add(fw, p, x);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            out(Sum(fw, l, r));
        }
    }

    free(fw->data);
    free(fw);
    return 0;
}

// <END-OF-CODE>
