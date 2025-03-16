#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    int *arr = malloc(n * sizeof(int)); // Allocate memory for the array

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element
    }

    qsort(arr, n, sizeof(int), compare); // Sort the array

    int first = arr[0]; // The smallest element
    int result = 1; // Default result is -1 (1 in C for boolean)

    for (int i = 0; i < n; i++) {
        if (arr[i] % first != 0) {
            result = 0; // If any element is not divisible by the smallest, set result to 0
            break;
        }
    }

    printf("%d\n", result ? first : -1); // Print the result
    free(arr); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
