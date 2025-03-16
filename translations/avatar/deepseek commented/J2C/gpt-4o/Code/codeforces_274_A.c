#include <stdio.h> // Step 1: Include necessary headers
#include <stdlib.h> // For qsort
#include <stdbool.h> // For using boolean values

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    int n;
    long long k;
    
    // Step 2: Read input values
    scanf("%d", &n);
    scanf("%lld", &k);
    
    long long *arr = (long long *)malloc(n * sizeof(long long)); // Step 3: Allocate memory for the array
    bool *set = (bool *)calloc(2000000, sizeof(bool)); // Step 3: Create a boolean array to simulate a HashSet

    // Step 4: Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // Step 5: Sort the array
    qsort(arr, n, sizeof(long long), compare);

    int count = 0; // Step 6: Initialize count variable

    // Step 7: Iterate through the array
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) { // Check if the element is not divisible by k
            count++; // Increment the count
            set[arr[i] + 1000000] = true; // Add the element to the set (offset for negative values)
        } else if (!set[arr[i] / k + 1000000]) { // Check if the quotient is not in the set
            count++; // Increment the count
            set[arr[i] + 1000000] = true; // Add the element to the set
        }
    }

    printf("%d\n", count); // Step 8: Print the result

    // Free allocated memory
    free(arr);
    free(set);

    return 0;
}
