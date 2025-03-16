#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
} BIT;

BIT* createBIT(int N) {
    BIT *bit = (BIT*)malloc(sizeof(BIT));
    bit->size = N;
    bit->tree = (int*)calloc(N + 1, sizeof(int));
    return bit;
}

int _bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i ^= i & -i;
    }
    return ret;
}

int bitsum(BIT *bit, int l, int r) {
    return _bitsum(bit, r) - _bitsum(bit, l);
}

void bitadd(BIT *bit, int i, int x) {
    i += 1;
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
    int *d = (int*)malloc((n + 1) * sizeof(int));
    int _a[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        _a[i] = a[i];
    }
    qsort(_a, n, sizeof(int), (int (*)(const void*, const void*))compare);
    for (int i = 0; i < n; i++) {
        d[_a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    int check(int X) {
        int b[n + 1];
        for (int i = 0; i <= n; i++) {
            b[i] = (a[i - 1] >= X) * 2 - 1;
        }
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1];
        }
        int c = b[0];
        for (int i = 1; i <= n; i++) {
            if (b[i] < c) {
                c = b[i];
            }
        }
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }
        BIT *bit = createBIT(n + 2);
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += bitsum(bit, b[i] + 1, n + 1);
            bitadd(bit, b[i], 1);
        }
        return ans >= m;
    }

    int t[2] = {n, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check(mid)) {
            t[0] = mid;
        } else {
            t[1] = mid;
        }
    }

    printf("%d\n", _a[t[1]]);

    free(d);
    free(bit->tree);
    free(bit);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
