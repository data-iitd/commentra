#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read integers from input
void readInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);  // Read integer n
    int *A = (int *)malloc(2 * n * sizeof(int));  // Allocate memory for array A
    readInts(A, 2 * n);  // Read list A

    qsort(A, 2 * n, sizeof(int), compare);  // Sort the list A

    long long ans = 0;  // Initialize answer variable

    // Calculate the sum of every second element from the end
    for (int i = 2 * n - 2; i >= n - 1; i -= 2) {
        ans += A[i];
    }

    printf("%lld\n", ans);  // Print the calculated sum

    free(A);  // Free allocated memory
    return 0;
}

// <END-OF-CODE>
