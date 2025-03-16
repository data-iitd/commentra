#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

int tree[MAX + 1];
int size;
int depth;

void bitsum(int l, int r) {
    int ret = 0;
    while (l) {
        ret += tree[l];
        l ^= l & -l;
    }
    while (r) {
        ret -= tree[r];
        r ^= r & -r;
    }
    return ret;
}

void bitadd(int i, int x) {
    i++;
    while (i <= size) {
        tree[i] += x;
        i += i & -i;
    }
    return;
}

int main() {
    int n, m, i, x, l, r;
    int a[MAX];
    int d[MAX];
    int _a[MAX];
    int c;
    int bit;
    int ans;

    scanf("%d", &n);
    m = n * (n + 1) / 4;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        d[a[i]] = i;
    }
    for (i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    for (i = 0; i < n; i++) {
        _a[i] = a[i];
    }
    qsort(_a, n, sizeof(int), cmp);
    for (i = 0; i < n; i++) {
        a[i] = d[_a[i]];
    }

    size = n;
    depth = (int)log2(n);

    for (i = 0; i < n; i++) {
        if (a[i] >= i) {
            bit = 2;
        } else {
            bit = -2;
        }
        bitadd(a[i], bit);
    }

    for (i = 0; i < n; i++) {
        ans = bitsum(a[i] + 1, a[i]);
        if (ans >= m) {
            printf("%d\n", _a[i]);
            return 0;
        }
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

