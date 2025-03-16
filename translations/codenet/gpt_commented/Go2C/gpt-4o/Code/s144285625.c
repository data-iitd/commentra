#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
<<<<<<< HEAD
    
=======
>>>>>>> 98c87cb78a (data updated)
    // Read the number of groups of three integers
    scanf("%d", &n);

    // Initialize an array to hold 3*n integers
    int *ar = (int *)malloc(3 * n * sizeof(int));

    // Populate the array with integers from input
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &ar[i]);
    }

    // Sort the array of integers in ascending order
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

// <END-OF-CODE>
