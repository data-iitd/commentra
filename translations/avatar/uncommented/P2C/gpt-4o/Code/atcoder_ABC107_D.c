#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
} BIT;

BIT* createBIT(int N) {
    BIT *bit = (BIT *)malloc(sizeof(BIT));
    bit->size = N;
    bit->tree = (int *)calloc(N + 1, sizeof(int));
    return bit;
}

void freeBIT(BIT *bit) {
    free(bit->tree);
    free(bit);
}

void bitAdd(BIT *bit, int i, int x) {
    i += 1;
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;
    }
}

int bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i ^= i & -i;
    }
    return ret;
}

int rangeBitsum(BIT *bit, int l, int r) {
    return bitsum(bit, r) - bitsum(bit, l);
}

int check(int *a, int n, int X, int m) {
    int *b = (int *)malloc((n + 1) * sizeof(int));
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);
    }
    int c = b[0];
    for (int i = 1; i <= n; i++) {
        if (b[i] < c) c = b[i];
    }
    for (int i = 0; i <= n; i++) {
        b[i] -= c;
    }
    BIT *bit = createBIT(n + 1);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += bitsum(bit, b[i] + 1);
        bitAdd(bit, b[i], 1);
    }
    freeBIT(bit);
    free(b);
    return ans >= m;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4;
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create a sorted unique array
    int *unique = (int *)malloc((n + 1) * sizeof(int));
    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        unique[uniqueCount++] = a[i];
    }
    unique[uniqueCount++] = 0;

    // Sort unique array
    qsort(unique, uniqueCount, sizeof(int), (int (*)(const void *, const void *))compare);
    
    // Create a mapping from value to index
    int *d = (int *)malloc((uniqueCount) * sizeof(int));
    for (int i = 0; i < uniqueCount; i++) {
        d[unique[i]] = i;
    }

    // Remap a
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    int t[2] = {uniqueCount, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        t[check(a, n, mid, m)] = mid;
    }
    printf("%d\n", unique[t[1]]);

    free(a);
    free(unique);
    free(d);
    return 0;
}

int compare(const int *a, const int *b) {
    return (*a - *b);
}

// <END-OF-CODE>
