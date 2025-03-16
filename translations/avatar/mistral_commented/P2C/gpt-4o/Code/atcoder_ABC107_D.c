#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
} BIT;

// Initialize an instance of BIT with a given size N
BIT* createBIT(int N) {
    BIT *bit = (BIT *)malloc(sizeof(BIT));
    bit->size = N;
    bit->tree = (int *)calloc(N + 1, sizeof(int)); // Initialize tree array with zeros
    return bit;
}

// Helper function to calculate the sum of bits from index i to 0
int bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i) {
        ret += bit->tree[i];
        i &= i - 1; // Bitwise AND with the rightmost set bit
    }
    return ret;
}

// Function to calculate the sum of bits from left index l to right index r
int rangeBitsum(BIT *bit, int l, int r) {
    if (r == -1) {
        return bitsum(bit, l);
    } else {
        return bitsum(bit, r) - bitsum(bit, l);
    }
}

// Function to add a value x to the index i in the tree
void bitadd(BIT *bit, int i, int x) {
    i += 1; // Index i is 1-based in the tree
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i; // Bitwise right propagation
    }
}

// Function to check if a given value X is a valid answer
int check(int *a, int n, int X) {
    int *b = (int *)malloc((n + 1) * sizeof(int));
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);
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
    BIT *bit = createBIT(n + 2); // Initialize BIT tree with the maximum value in b + 2
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += rangeBitsum(bit, b[i] + 1, n + 1); // Calculate the sum of bits from index b[i]+1 to the end
        bitadd(bit, b[i], 1); // Add 1 to the index b[i] in the tree
    }
    free(b);
    free(bit->tree);
    free(bit);
    return ans >= (n * (n + 1)) / 4; // m = n * (n + 1) / 4
}

int main() {
    int n;
    scanf("%d", &n);

    int m = n * (n + 1) / 4;

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create a dictionary d to map each unique value in a to its index
    int *d = (int *)malloc((n + 1) * sizeof(int));
    int *_a = (int *)malloc((n + 1) * sizeof(int));
    int uniqueCount = 0;

    // Sort and create unique values
    for (int i = 0; i < n; i++) {
        _a[uniqueCount++] = a[i];
    }
    _a[uniqueCount++] = 0; // Include 0
    qsort(_a, uniqueCount, sizeof(int), cmpfunc);
    
    for (int i = 0; i < uniqueCount; i++) {
        d[_a[i]] = i;
    }

    // Replace the original array a with its indices in the dictionary d
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    // Binary search to find the answer
    int left = 0, right = uniqueCount;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(a, n, _a[mid])) {
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%d\n", _a[left]);

    free(a);
    free(d);
    free(_a);
    return 0;
}

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// <END-OF-CODE>
