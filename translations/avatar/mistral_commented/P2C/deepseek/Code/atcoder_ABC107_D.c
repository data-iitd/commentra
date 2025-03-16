#include <stdio.h>
#include <stdlib.h>

// Define the size of the BIT tree
#define MAXN 100005

// Class definition for BIT (Binary Indexed Tree)
typedef struct {
    int size;
    int tree[MAXN];
} BIT;

// Function to initialize an instance of BIT with a given size N
void BIT_init(BIT *bit, int N) {
    bit->size = N;
    for (int i = 0; i <= N; i++) {
        bit->tree[i] = 0;
    }
}

// Helper function to calculate the sum of bits from index i to 0
int _bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i > 0) {
        ret += bit->tree[i];
        i &= i - 1;  // Bitwise AND with the rightmost set bit
    }
    return ret;
}

// Function to calculate the sum of bits from left index l to right index r
int bitsum(BIT *bit, int l, int r) {
    return _bitsum(bit, r) - _bitsum(bit, l);
}

// Function to add a value x to the index i in the tree
void bitadd(BIT *bit, int i, int x) {
    i += 1;  // Index i is 1-based in the tree
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;  // Bitwise right propagation
    }
}

// Read input values
int n;
scanf("%d", &n);

// Calculate the size of the BIT tree
int m = n * (n + 1) / 4;

// Read input array a
int a[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
}

// Create a dictionary d to map each unique value in a to its index
int d[MAXN];
int _a[MAXN];
int unique_count = 0;
for (int i = 0; i < n; i++) {
    _a[i] = a[i];
}
_a[n] = 0;
qsort(_a, n + 1, sizeof(int), (int (*)(const void *, const void *))cmp);
for (int i = 0; i <= n; i++) {
    if (i == 0 || _a[i] != _a[i - 1]) {
        d[_a[i]] = unique_count++;
    }
}

// Replace the original array a with its indices in the dictionary d
for (int i = 0; i < n; i++) {
    a[i] = d[a[i]];
}

// Function to check if a given value X is a valid answer
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
    BIT bit;
    BIT_init(&bit, b[n] + 1);
    int ans = 0;
    for (int x : b) {
        ans += bitsum(&bit, x + 1, b[n] + 1);
        bitadd(&bit, x, 1);
    }
    return ans >= m;
}

// Binary search to find the answer
int t[2] = {unique_count, 0};
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;
    if (check(mid)) {
        t[1] = mid;
    } else {
        t[0] = mid;
    }
}

// Print the answer
printf("%d\n", _a[t[1]]);

