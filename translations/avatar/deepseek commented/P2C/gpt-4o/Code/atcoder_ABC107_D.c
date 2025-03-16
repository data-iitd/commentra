#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
} BIT;

BIT* createBIT(int N) {
    BIT *bit = (BIT *)malloc(sizeof(BIT));
    bit->size = N;
    bit->tree = (int *)calloc(N + 1, sizeof(int)); // Initialize the tree array
    return bit;
}

void freeBIT(BIT *bit) {
    free(bit->tree);
    free(bit);
}

void bitAdd(BIT *bit, int i, int x) {
    i += 1; // Convert to 1-based index
    while (i <= bit->size) {
        bit->tree[i] += x; // Add x to the current index
        i += i & -i; // Move to the next index
    }
}

int bitsum(BIT *bit, int i) {
    int ret = 0; // Initialize the sum to 0
    while (i) {
        ret += bit->tree[i]; // Add the value at the current index
        i ^= i & -i; // Move to the parent index using the binary representation
    }
    return ret; // Return the sum
}

int rangeSum(BIT *bit, int l, int r) {
    if (r == -1) {
        return bitsum(bit, l); // Calculate sum from 1 to l if r is not provided
    } else {
        return bitsum(bit, r) - bitsum(bit, l); // Calculate sum from l to r
    }
}

int check(int *a, int n, int X, int m) {
    int *b = (int *)malloc((n + 1) * sizeof(int));
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1); // Create a binary array
    }
    int c = b[0];
    for (int i = 1; i <= n; i++) {
        if (b[i] < c) c = b[i]; // Normalize the array to be non-negative
    }
    for (int i = 0; i <= n; i++) {
        b[i] -= c; // Normalize
    }
    BIT *bit = createBIT(n + 1); // Initialize the BIT
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += rangeSum(bit, b[i], -1); // Count inversions using the BIT
        bitAdd(bit, b[i], 1); // Add 1 to the current index in the BIT
    }
    freeBIT(bit);
    free(b);
    return ans >= m;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4; // Calculate the median position
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
    unique[uniqueCount++] = 0; // Include 0
    qsort(unique, uniqueCount, sizeof(int), cmp); // Sort the array
    uniqueCount = uniqueCount; // Update unique count

    // Create a mapping from value to index
    int *d = (int *)malloc((uniqueCount) * sizeof(int));
    for (int i = 0; i < uniqueCount; i++) {
        d[unique[i]] = i; // Map value to index
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]]; // Convert to indices
    }

    // Binary search to find the value of X
    int low = 0, high = uniqueCount;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (check(a, n, unique[mid], m)) {
            low = mid; // Move to the right half
        } else {
            high = mid; // Move to the left half
        }
    }

    printf("%d\n", unique[low]); // Output the median value

    free(a);
    free(unique);
    free(d);
    return 0;
}

// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// <END-OF-CODE>
