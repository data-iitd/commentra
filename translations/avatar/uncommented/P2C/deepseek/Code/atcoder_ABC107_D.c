#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int* tree;
    int depth;
} BIT;

BIT* createBIT(int N) {
    BIT* bit = (BIT*)malloc(sizeof(BIT));
    bit->size = N;
    bit->tree = (int*)calloc(N + 1, sizeof(int));
    bit->depth = 32 - __builtin_clz(N);
    return bit;
}

int _bitsum(BIT* bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i ^= i & -i;
    }
    return ret;
}

int bitsum(BIT* bit, int l, int r) {
    if (r == -1) {
        return _bitsum(bit, l);
    } else {
        return _bitsum(bit, r) - _bitsum(bit, l);
    }
}

void bitadd(BIT* bit, int i, int x) {
    i += 1;
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    m = n * (n + 1) / 4;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int* _a = (int*)malloc((n + 1) * sizeof(int));
    memcpy(_a, a, n * sizeof(int));
    _a[n] = 0;
    qsort(a, n + 1, sizeof(int), (int (*)(const void*, const void*))compare);

    int* d = (int*)malloc((n + 1) * sizeof(int));
    int* unique_a = (int*)malloc((n + 1) * sizeof(int));
    int unique_count = 0;
    for (int i = 0; i <= n; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (_a[i] == unique_a[j]) {
                found = 1;
                d[i] = j;
                break;
            }
        }
        if (!found) {
            unique_a[unique_count++] = _a[i];
            d[i] = unique_count - 1;
        }
    }

    int check(int X) {
        int b[n + 1];
        for (int i = 0; i <= n; i++) {
            b[i] = (a[i] >= X) * 2 - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        int c = b[0];
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }
        BIT* bit = createBIT(b[n] + 1);
        int ans = 0;
        for (int x : b) {
            ans += bitsum(bit, x + 1, -1);
            bitadd(bit, x, 1);
        }
        free(bit->tree);
        free(bit);
        return ans >= m;
    }

    int t[2] = {unique_count, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check(unique_a[mid])) {
            t[1] = mid;
        } else {
            t[0] = mid;
        }
    }
    printf("%d\n", unique_a[t[1]]);

    free(_a);
    free(d);
    free(unique_a);
    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
