#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read an integer input for the number of elements
    int n;
    scanf("%d", &n);

    // Allocate memory for the array of integers
    int *l1 = (int *)malloc(n * sizeof(int));

    // Read the integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]);
    }

    // Sort the array of integers in ascending order
    qsort(l1, n, sizeof(int), compare);

    // Assign the maximum value in the array to variable 'a'
    int a = l1[n - 1];

    // Assign the minimum value in the array to variable 'b'
    int b = l1[0];

    // Check if the maximum and minimum values are the same
    if (a == b) {
        // If they are the same, the difference is zero and the number of pairs is n choose 2
        printf("%d %d\n", a - b, (n * (n - 1)) / 2);
    } else {
        // Count occurrences of the maximum value 'a' in the array
        int ac = 0;
        for (int i = 0; i < n; i++) {
            if (l1[i] == a) {
                ac++;
            }
        }

        // Count occurrences of the minimum value 'b' in the array
        int bc = 0;
        for (int i = 0; i < n; i++) {
            if (l1[i] == b) {
                bc++;
            }
        }

        // Calculate the difference between the maximum and minimum values, and the product of their counts
        printf("%d %d\n", a - b, ac * bc);
    }

    // Free the allocated memory
    free(l1);

    return 0;
}

// <END-OF-CODE>
