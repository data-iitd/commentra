#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int *tree;
} BIT;

// Initialize the Binary Indexed Tree (BIT) with size N
void BIT_init(BIT *bit, int N) {
    bit->size = N;
    bit->tree = (int *)calloc(N + 1, sizeof(int)); // Initialize the BIT array with zeros
}

// Internal method to calculate the prefix sum up to index i
int bitsum(BIT *bit, int i) {
    int ret = 0; // Initialize the sum
    while (i) {
        ret += bit->tree[i]; // Add the value at index i to the sum
        i ^= i & -i; // Move to the parent index
    }
    return ret; // Return the calculated sum
}

// Public method to calculate the sum in the range [l, r]
int bitsum_range(BIT *bit, int l, int r) {
    if (r == -1) {
        return bitsum(bit, l); // If r is not provided, return the sum up to l
    } else {
        return bitsum(bit, r) - bitsum(bit, l); // Return the sum in the range [l, r]
    }
}

// Method to add a value x at index i
void bitadd(BIT *bit, int i, int x) {
    i += 1; // Adjust index to match BIT's 1-based indexing
    while (i <= bit->size) {
        bit->tree[i] += x; // Update the BIT with the value x
        i += i & -i; // Move to the next index
    }
}

// Function to check if a certain value X can be achieved
int check(int *a, int n, int X, int m) {
    int *b = (int *)malloc((n + 1) * sizeof(int));
    b[0] = 0; // Initialize b[0]
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X) * 2 - 1 + b[i]; // Calculate prefix sums
    }
    int c = b[0];
    for (int i = 1; i <= n; i++) {
        if (b[i] < c) c = b[i]; // Find the minimum value in b
    }
    for (int i = 0; i <= n; i++) {
        b[i] -= c; // Normalize b by subtracting the minimum value
    }
    BIT bit;
    BIT_init(&bit, n + 2); // Initialize a BIT for the range of b
    int ans = 0; // Initialize the answer counter
    // Count the number of valid pairs using the BIT
    for (int i = 0; i <= n; i++) {
        ans += bitsum_range(&bit, b[i] + 1, -1); // Count how many indices have been added that are less than b[i]
        bitadd(&bit, b[i], 1); // Add the current index to the BIT
    }
    free(b);
    return ans >= m; // Return whether the count is at least m
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4; // Calculate the target value m based on the number of elements
    int *a = (int *)malloc(n * sizeof(int)); // Read the input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Create a sorted list of unique values from a, including 0
    int *unique = (int *)malloc((n + 1) * sizeof(int));
    memcpy(unique, a, n * sizeof(int));
    unique[n] = 0; // Include 0
    qsort(unique, n + 1, sizeof(int), (int (*)(const void *, const void *))strcmp);
    
    // Remove duplicates
    int unique_count = 0;
    for (int i = 0; i < n + 1; i++) {
        if (i == 0 || unique[i] != unique[i - 1]) {
            unique[unique_count++] = unique[i];
        }
    }
    
    // Map original values in a to their indices in the sorted list
    int *d = (int *)malloc(unique_count * sizeof(int));
    for (int i = 0; i < unique_count; i++) {
        d[unique[i]] = i; // Map original values to their indices
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]]; // Replace original values in a with their corresponding indices
    }
    
    // Initialize the binary search bounds
    int left = 0, right = unique_count;
    while (right - left > 1) {
        int mid = (left + right) / 2; // Calculate the midpoint
        if (check(a, n, unique[mid], m)) {
            left = mid; // Update the bounds based on the check function
        } else {
            right = mid;
        }
    }
    
    // Print the result corresponding to the found index
    printf("%d\n", unique[left]);
    
    // Free allocated memory
    free(a);
    free(unique);
    free(d);
    return 0;
}

// <END-OF-CODE>
