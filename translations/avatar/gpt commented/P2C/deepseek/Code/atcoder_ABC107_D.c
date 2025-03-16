#include <stdio.h>
#include <stdlib.h>

// Define the size of the BIT
#define MAXN 100005

// Define the BIT structure
typedef struct {
    int size;
    int tree[MAXN];
} BIT;

// Function to initialize the BIT
void BIT_init(BIT *bit, int N) {
    bit->size = N;
    for (int i = 0; i <= N; i++) {
        bit->tree[i] = 0;
    }
}

// Function to calculate the prefix sum up to index i
int _bitsum(BIT *bit, int i) {
    int ret = 0;
    while (i > 0) {
        ret += bit->tree[i];
        i ^= i & -i;
    }
    return ret;
}

// Function to calculate the sum in the range [l, r]
int bitsum(BIT *bit, int l, int r) {
    return _bitsum(bit, r) - _bitsum(bit, l - 1);
}

// Function to add a value x at index i
void bitadd(BIT *bit, int i, int x) {
    i++;
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;
    }
}

// Function to check if a certain value X can be achieved
int check(int X, int n, int *a, int *d, int *_a) {
    // Create a new list b where each element indicates if the corresponding a[i] is >= X
    int b[n + 1];
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X) * 2 - 1;
    }
    // Calculate the prefix sums of b
    for (int i = 0; i < n; i++) {
        b[i + 1] += b[i];
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
    BIT bit;
    BIT_init(&bit, MAXN);
    int ans = 0;
    // Count the number of valid pairs using the BIT
    for (int x = 0; x <= n; x++) {
        ans += bitsum(&bit, x + 1, MAXN);
        bitadd(&bit, x, 1);
    }
    return ans >= (n * (n + 1) / 4);
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Create a sorted list of unique values from a, including 0
    int _a[n + 1];
    for (int i = 0; i < n; i++) {
        _a[i] = a[i];
    }
    _a[n] = 0;
    qsort(_a, n + 1, sizeof(int), (int (*)(const void *, const void *))cmp);
    // Map original values to their indices in the sorted list
    int d[n + 1];
    for (int i = 0; i <= n; i++) {
        d[_a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }
    // Perform binary search to find the maximum value that satisfies the condition
    int t[2] = {n, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check(mid, n, a, d, _a)) {
            t[0] = mid;
        } else {
            t[1] = mid;
        }
    }
    // Print the result corresponding to the found index
    printf("%d\n", _a[t[1]]);
    return 0;
}

