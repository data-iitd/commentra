
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
    int depth;
} BIT;

void _bitsum(BIT *bit, int i, int *ret) {
    *ret = 0;
    while (i) {
        *ret += bit->tree[i];
        i ^= i & -i;
    }
}

int bitsum(BIT *bit, int l, int r) {
    if (r == -1) {
        return _bitsum(bit, l, ret);
    } else {
        return _bitsum(bit, r) - _bitsum(bit, l);
    }
}

void bitadd(BIT *bit, int i, int x) {
    i++;
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4;
    int a[n];
    int d[n * 2];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        d[i * 2] = a[i];
        d[i * 2 + 1] = 0;
    }
    d[n * 2] = 0;
    qsort(d, n * 2 + 1, sizeof(int), cmpfunc);
    int _a[n];
    for (int i = 0; i < n; i++) {
        _a[i] = lower_bound(d, d + n * 2 + 1, a[i]) - d;
    }

    int ok = n * 2;
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        BIT bit;
        bit.size = mid;
        bit.tree = (int *)malloc(sizeof(int) * (mid + 1));
        for (int i = 0; i <= mid; i++) {
            bit.tree[i] = 0;
        }
        bit.depth = mid.bit_length();
        int b[n];
        for (int i = 0; i < n; i++) {
            b[i] = (_a[i] >= mid) * 2 - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i] += b[i - 1];
        }
        int c = *min_element(b, b + n);
        for (int i = 0; i < n; i++) {
            b[i] -= c;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += bitsum(&bit, b[i] + 1, -1);
            bitadd(&bit, b[i], 1);
        }
        if (ans >= m) {
            ok = mid;
        } else {
            ng = mid;
        }
        free(bit.tree);
    }
    printf("%d\n", d[ok]);
    return 0;
}

Translate the above C code to Java and end with comment "