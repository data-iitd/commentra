#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    
    // Read two integers `n` and `k` from the standard input
    scanf("%d %d", &n, &k);
    
    // Create an array to hold the integers
    int *numbers = (int *)malloc(n * sizeof(int));
    
    // Read `n` integers from the standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Sort the array in ascending order
    qsort(numbers, n, sizeof(int), compare);
    
    // Calculate the sum of the first `k` elements of the sorted array
    int result = 0;
    for (int i = 0; i < k; i++) {
        result += numbers[i];
    }
    
    // Print the result
    printf("%d\n", result);
    
    // Free the allocated memory
    free(numbers);
    
    return 0;
}

// <END-OF-CODE>
