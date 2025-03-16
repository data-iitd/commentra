#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int getInt() {
    int ret;
    scanf("%d", &ret);
    return ret;
}

// Function to read a slice of integers from input
int* getIntSlice(int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ret[i] = getInt();
    }
    return ret;
}

// Function to compute the absolute value of an integer
int abs(int n) {
    return n < 0 ? -n : n;
}

// Function to compute the minimum total distance to a median value
void solve() {
    // Read the number of elements
    int n = getInt();
    // Read the integer slice of size n
    int* as = getIntSlice(n);

    // Create a new slice to store adjusted values
    int* xs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        // Adjust each element by subtracting its index and adding 1
        xs[i] = as[i] - i + 1;
    }
    // Sort the adjusted values
    qsort(xs, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Find the median value from the sorted slice
    int b = xs[n / 2];
    int ans = 0;
    // Calculate the total distance from each element to the median
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    // Output the result
    printf("%d\n", ans);

    // Free allocated memory
    free(as);
    free(xs);
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function to initialize input/output and call the solve function
int main() {
    // Call the solve function to perform the main logic
    solve();
    return 0;
}
