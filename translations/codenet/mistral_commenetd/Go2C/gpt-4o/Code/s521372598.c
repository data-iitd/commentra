#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the absolute value
int abs(int n) {
    return n < 0 ? -n : n;
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solve() {
    int n;
    scanf("%d", &n); // Read the number of elements in the array

    int *as = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]); // Read the array elements
    }

    int *xs = (int *)malloc(n * sizeof(int)); // Allocate memory for the xs array
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
    }

    // Sort the array xs in ascending order
    qsort(xs, n, sizeof(int), compare);

    // Assign the middle element of the sorted array xs to variable b
    int b = xs[n / 2];
    int ans = 0;

    // Iterate through the array xs and calculate the absolute difference
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b); // Calculate the absolute difference and add it to ans
    }

    // Print the answer
    printf("%d\n", ans);

    // Free allocated memory
    free(as);
    free(xs);
}

int main() {
    solve(); // Call the solve function
    return 0;
}

// <END-OF-CODE>
