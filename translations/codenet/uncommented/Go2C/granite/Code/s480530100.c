
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *data;
} BIT;

BIT* FenwickTree(int n) {
    BIT *ret = (BIT*)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int*)malloc(sizeof(int) * n);
    return ret;
}

void Add(BIT *b, int p, int x) {
    p++;
    for (int i = p; i <= b->n; i += i & -i) {
        b->data[i-1] += x;
    }
}

int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l);
}

int sum(BIT *b, int r) {
    int s = 0;
    for (int i = r; i > 0; i -= i & -i) {
        s += b->data[i-1];
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
            printf("%d\n", Sum(fw, l, r));
        }
    }

    return 0;
}
