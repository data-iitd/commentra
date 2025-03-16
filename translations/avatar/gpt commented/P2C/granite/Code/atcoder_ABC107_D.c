
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
    int depth;
} BIT;

// Initialize the Binary Indexed Tree (BIT) with size N
void initBIT(BIT *bit, int N) {
    bit->size = N;  // Store the size of the BIT
    bit->tree = (int *)malloc(sizeof(int) * (N + 1));  // Initialize the BIT array with zeros
    for (int i = 0; i <= N; i++) {
        bit->tree[i] = 0;
    }
    bit->depth = N.bit_length();  // Calculate the depth of the BIT
}

// Internal method to calculate the prefix sum up to index i
int bitsum(BIT *bit, int i) {
    int ret = 0;  // Initialize the sum
    while (i) {
        ret += bit->tree[i];  // Add the value at index i to the sum
        i ^= i & -i;  // Move to the parent index
    }
    return ret;  // Return the calculated sum
}

// Public method to calculate the sum in the range [l, r]
int rangeBitsum(BIT *bit, int l, int r) {
    if (r == -1) {
        r = l;  // If r is not provided, set it to l
    }
    return bitsum(bit, r) - bitsum(bit, l);  // Return the sum in the range [l, r]
}

// Method to add a value x at index i
void bitadd(BIT *bit, int i, int x) {
    i++;  // Adjust index to match BIT's 1-based indexing
    while (i <= bit->size) {
        bit->tree[i] += x;  // Update the BIT with the value x
        i += i & -i;  // Move to the next index
    }
}

int main() {
    int n;  // Number of elements
    scanf("%d", &n);  // Read the number of elements
    int m = n * (n + 1) / 4;  // Calculate the target value m based on the number of elements
    int a[n];  // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read the input array
    }
    int d[n];  // Dictionary to hold the mapping of values to their indices
    int _a[n * 2];  // Sorted list of unique values from a, including 0
    for (int i = 0; i < n; i++) {
        _a[i * 2] = a[i];  // Copy original values to _a
        _a[i * 2 + 1] = 0;  // Add 0 to _a
    }
    _a[n * 2] = 0;  // Add 0 to the end of _a
    qsort(_a, n * 2 + 1, sizeof(int), cmpfunc);  // Sort _a in ascending order
    int k = 0;  // Initialize the index for mapping original values to their indices in the sorted list
    for (int i = 0; i < n * 2; i++) {
        if (i == 0 || _a[i]!= _a[i - 1]) {
            d[_a[i]] = k++;  // Map original values to their indices in the sorted list
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];  // Replace original values in a with their corresponding indices
    }
    int b[n];  // List b where each element indicates if the corresponding a[i] is >= X
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] >= m) * 2 - 1;  // Set b[i] to 1 if a[i] >= m, otherwise set it to -1
    }
    int c[n];  // Prefix sums of b
    for (int i = 0; i < n; i++) {
        c[i] = b[i] + (i == 0? 0 : c[i - 1]);  // Calculate the prefix sums of b
    }
    int min_c = *min_element(c, c + n);  // Find the minimum value in c
    for (int i = 0; i < n; i++) {
        c[i] -= min_c;  // Normalize c by subtracting the minimum value
    }
    BIT bit;  // Initialize a BIT for the range of c
    initBIT(&bit, *max_element(c, c + n) + 2);  // Initialize the BIT with the maximum value in c plus 2
    int ans = 0;  // Initialize the answer counter
    for (int i = 0; i < n; i++) {
        ans += rangeBitsum(&bit, c[i] + 1, bit.size);  // Count how many indices have been added that are less than c[i]
        bitadd(&bit, c[i], 1);  // Add the current index to the BIT
    }
    int X = 0;  // Initialize the binary search bounds
    while (X < k && rangeBitsum(&bit, d[X] + 1, bit.size) < m) {
        X++;  // Increment X if the count is less than m
    }
    printf("%d\n", _a[X]);  // Print the result corresponding to the found index
    return 0;
}

