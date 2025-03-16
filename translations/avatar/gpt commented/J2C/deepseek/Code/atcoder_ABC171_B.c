#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next token as an integer
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to solve the problem
void solve(void) {
    // Read the number of elements (n) and the number of smallest elements to sum (k)
    int n = readInt();
    int k = readInt();

    // Initialize an array to hold the input numbers
    int* a = (int*)malloc(n * sizeof(int));

    // Read n integers from input and store them in the array
    for (int i = 0; i < n; ++i) {
        a[i] = readInt();
    }

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Initialize a variable to hold the sum of the smallest k elements
    int ans = 0;

    // Sum the first k elements of the sorted array
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }

    // Output the result (sum of the smallest k elements)
    printf("%d\n", ans);

    // Free the allocated memory
    free(a);
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    // Call the solve function to process the input and produce output
    solve();
    return 0;
}
