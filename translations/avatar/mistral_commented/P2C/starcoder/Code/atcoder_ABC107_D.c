
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Class definition for BIT (Binary Indexed Tree)
// Initialize an instance of BIT with a given size N
typedef struct {
    int size;
    int *tree;
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
    return _bitsum(bit, r) - _bitsum(bit, l);
}

// Function to add a value x to the index i in the tree
void bitadd(BIT *bit, int i, int x) {
    i += 1;  // Index i is 1-based in the tree
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;  // Bitwise right propagation
}

// Read input values
int n;
scanf("%d", &n);

// Calculate the size of the BIT tree
int m = n * (n + 1) / 4;

// Read input array a
int *a = (int *) malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
}

// Create a dictionary d to map each unique value in a to its index
int *d = (int *) malloc((n + 1) * sizeof(int));
int _a[n + 1];
int _a_size = 0;
for (int i = 0; i < n; i++) {
    if (d[a[i]] == 0) {
        d[a[i]] = _a_size;
        _a[_a_size++] = a[i];
    }
    a[i] = d[a[i]];
}

// Function to check if a given value X is a valid answer
bool check(int X) {
    int *b = (int *) malloc((n + 1) * sizeof(int));
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i+1] = (a[i] >= X) * 2 - 1;
    }
    for (int i = 0; i < n; i++) {
        b[i+1] += b[i];
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        c = c < b[i]? b[i] : c;
    }
    for (int i = 0; i < n; i++) {
        b[i] -= c;
    }
    BIT bit;
    bit.size = 0;
    bit.tree = (int *) malloc((n + 2) * sizeof(int));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bitsum(&bit, b[i] + 1);  // Calculate the sum of bits from index b[i] + 1 to the end
        bitadd(&bit, b[i], 1);  // Add 1 to the index b[i] in the tree
    }
    free(bit.tree);
    return ans >= m;
}

// Binary search to find the answer
int t[2] = {n, 0};
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;
    t[check(mid)] = mid;
}

// Print the answer
printf("%d\n", _a[t[1]]);

