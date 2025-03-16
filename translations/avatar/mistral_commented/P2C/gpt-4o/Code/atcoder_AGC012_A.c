#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read integers from standard input
void readInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);
    
    int *A = (int *)malloc(n * sizeof(int));
    readInts(A, n);
    
    // Sort the array A in ascending order
    qsort(A, n, sizeof(int), compare);
    
    long long ans = 0; // Use long long to avoid overflow
    for (int i = n - 2; i >= n - 2 * n; i -= 2) {
        ans += A[i];
    }
    
    printf("%lld\n", ans);
    
    free(A); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
