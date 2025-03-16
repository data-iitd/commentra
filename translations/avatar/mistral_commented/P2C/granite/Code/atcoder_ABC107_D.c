
###
# C implementation of the BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
###
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
    int depth;
} BIT;

// Helper function to calculate the sum of bits from index i to 0
int _bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i &= i - 1;  // Bitwise AND with the rightmost set bit
    }
    return ret;
}

// Function to calculate the sum of bits from left index l to right index r
int bitsum(BIT *bit, int l, int r) {
    if (r == -1) {
        return _bitsum(bit, l);
    } else {
        return _bitsum(bit, r) - _bitsum(bit, l);
    }
}

// Function to add a value x to the index i in the tree
void bitadd(BIT *bit, int i, int x) {
    i++;  // Index i is 1-based in the tree
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;  // Bitwise right propagation
    }
}

// Function to check if a given value X is a valid answer
int check(BIT *bit, int *a, int n, int X) {
    int b[n+1];
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i+1] = (a[i] >= X) * 2 - 1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i-1];
    }
    int c = *min_element(b, b+n+1);
    for (int i = 0; i <= n; i++) {
        b[i] -= c;
    }
    BIT *bit2 = (BIT*)malloc(sizeof(BIT));
    bit2->size = *max_element(b, b+n+1) + 2;
    bit2->tree = (int*)malloc(sizeof(int) * (bit2->size + 1));
    for (int i = 0; i <= bit2->size; i++) {
        bit2->tree[i] = 0;
    }
    bit2->depth = bit2->size.bit_length();
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += _bitsum(bit2, b[i]+1);  // Calculate the sum of bits from index b[i]+1 to the end
        bitadd(bit2, b[i], 1);  // Add 1 to the index b[i] in the tree
    }
    free(bit2->tree);
    free(bit2);
    return ans >= n * (n+1) / 4;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n+1) / 4;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int d[n];
    int _a[n];
    for (int i = 0; i < n; i++) {
        _a[i] = a[i];
    }
    sort(_a, _a+n);
    for (int i = 0; i < n; i++) {
        d[i] = lower_bound(_a, _a+n, a[i]) - _a;
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[i];
    }
    int t[2] = {n, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check((BIT*)NULL, a, n, mid)) {
            t[1] = mid;
        } else {
            t[0] = mid;
        }
    }
    printf("%d\n", _a[t[1]]);
    return 0;
}

Translate the above C code to Rust and end with comment "