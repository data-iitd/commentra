#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element into the array
    }

    qsort(arr, n, sizeof(int), compare); // Sort the array

    int smallest = arr[0];
    int divisible = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] % smallest == 0) {
            divisible = 1; // Check if any other element is divisible by the smallest
            break;
        }
    }

    if (divisible) {
        printf("%d\n", smallest); // Print the smallest element
    } else {
        printf("-1\n"); // Print -1 if no element is divisible
    }

    free(arr); // Free the allocated memory
    return 0;
}
// <END-OF-CODE>
