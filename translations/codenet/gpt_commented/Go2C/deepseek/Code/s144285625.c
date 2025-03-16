#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for 3*n integers
    int *ar = (int*)malloc(3 * n * sizeof(int));

    // Read the integers into the array
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &ar[i]);
    }

    // Sort the array in ascending order
    qsort(ar, 3 * n, sizeof(int), compare);

    // Initialize a variable to hold the sum of selected integers
    int sum = 0;

    // Calculate the sum of the second largest integer from each group of three
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2]; // Select the second largest integer from the sorted array
    }

    // Print the final computed sum
    printf("%d\n", sum);

    // Free the allocated memory
    free(ar);

    return 0;
}
