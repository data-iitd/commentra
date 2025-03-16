#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 1000000

// Class definition for BIT (Binary Indexed Tree)
typedef struct {
    int size;
    int tree[MAX_N + 1];
    int depth;
} BIT;

// Helper function to calculate the sum of bits from index i to 0
int bitsum(BIT *bit, int i) {
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
        return bitsum(bit, l);
    } else {
        return bitsum(bit, r) - bitsum(bit, l);
    }
}

// Function to add a value x to the index i in the tree
void bitadd(BIT *bit, int i, int x) {
    i += 1;  // Index i is 1-based in the tree
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;  // Bitwise right propagation
    }
}

int main() {
    int n, m, i, j, x, y, c, ans, mid;
    int a[MAX_N], b[MAX_N], d[MAX_N];
    BIT bit;

    // Read input values
    scanf("%d", &n);

    // Calculate the size of the BIT tree
    m = n * (n + 1) / 4;

    // Read input array a
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create a dictionary d to map each unique value in a to its index
    for (i = 0, j = 0; i < n; i++) {
        if (d[a[i]] == 0) {
            d[a[i]] = ++j;
        }
    }

    // Replace the original array a with its indices in the dictionary d
    for (i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    // Function to check if a given value X is a valid answer
    int check(int X) {
        for (i = 0; i < n; i++) {
            b[i] = (a[i] >= X) * 2 - 1;
        }
        for (i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        c = b[0];
        for (i = 0; i < n; i++) {
            b[i] -= c;
        }
        bit = (BIT){.size = MAX_N, .depth = MAX_N.bit_length()};
        ans = 0;
        for (i = 0; i < n; i++) {
            ans += bitsum(&bit, b[i] + 1);  // Calculate the sum of bits from index b[i] + 1 to the end
            bitadd(&bit, b[i], 1);  // Add 1 to the index b[i] in the tree
        }
        return ans >= m;
    }

    // Binary search to find the answer
    for (t[0] = MAX_N, t[1] = 0; t[0] - t[1] > 1;) {
        mid = (t[0] + t[1]) / 2;
        t[check(mid)] = mid;
    }

    // Print the answer
    printf("%d\n", t[1]);

    return 0;
}

