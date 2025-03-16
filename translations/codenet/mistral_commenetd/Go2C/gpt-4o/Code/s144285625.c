#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function
int main() {
    // Reading the number of elements in the array
    int n;
    scanf("%d", &n);

    // Allocating memory for the array
    int *ar = (int *)malloc(3 * n * sizeof(int));

    // Reading elements of the array
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &ar[i]);
    }

    // Sorting the array in ascending order
    qsort(ar, 3 * n, sizeof(int), compare);

    // Calculating the sum of elements at index 3n-2i-1 in the sorted array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2];
    }

    // Printing the result
    printf("%d\n", sum);

    // Freeing allocated memory
    free(ar);

    return 0;
}

// <END-OF-CODE>
