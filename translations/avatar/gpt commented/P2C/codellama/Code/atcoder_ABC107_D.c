#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000000
#define MAX_M 1000000

typedef struct {
    int size;
    int tree[MAX_N + 1];
    int depth;
} BIT;

// Initialize the Binary Indexed Tree (BIT) with size N
void initBIT(BIT *bit, int N) {
    bit->size = N;
    memset(bit->tree, 0, sizeof(int) * (N + 1));
    bit->depth = N.bit_length();
}

// Internal method to calculate the prefix sum up to index i
int bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i ^= i & -i;
    }
    return ret;
}

// Public method to calculate the sum in the range [l, r]
int bitsum(BIT *bit, int l, int r) {
    if (r == -1) {
        return bitsum(bit, l);
    } else {
        return bitsum(bit, r) - bitsum(bit, l);
    }
}

// Method to add a value x at index i
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
    int a[MAX_N];
    int d[MAX_N];
    memset(d, 0, sizeof(int) * MAX_N);
    int _a[MAX_N];
    int _a_size = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (d[a[i]] == 0) {
            d[a[i]] = _a_size;
            _a[_a_size++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    int check(int X) {
        int b[MAX_N];
        memset(b, 0, sizeof(int) * MAX_N);
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X) * 2 - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        int c = min(b);
        for (int i = 0; i < n; i++) {
            b[i] -= c;
        }
        BIT bit;
        initBIT(&bit, max(b) + 2);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += bitsum(&bit, b[i] + 1);
            bitadd(&bit, b[i], 1);
        }
        return ans >= m;
    }

    int t[2];
    t[0] = _a_size;
    t[1] = 0;
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        t[check(_a[mid])] = mid;
    }
    printf("%d\n", _a[t[1]]);
    return 0;
}

