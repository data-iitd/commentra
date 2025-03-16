#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the list
    int *l1 = (int *)malloc(n * sizeof(int)); // Allocate memory for the list

    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]); // Read the list elements
    }

    qsort(l1, n, sizeof(int), compare); // Sort the list in ascending order

    int a = l1[n - 1]; // Assign the last element of the sorted list to the variable a
    int b = l1[0]; // Assign the first element of the sorted list to the variable b

    if (a == b) { // Check if the first and the last elements are equal
        printf("%d %d\n", a - b, (n * (n - 1)) / 2); // If so, calculate and print the result
    } else {
        int ac = 0; // Count of occurrences of a
        int bc = 0; // Count of occurrences of b

        for (int i = 0; i < n; i++) {
            if (l1[i] == a) ac++; // Count occurrences of a
            if (l1[i] == b) bc++; // Count occurrences of b
        }

        printf("%d %d\n", a - b, ac * bc); // Print the result
    }

    free(l1); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
