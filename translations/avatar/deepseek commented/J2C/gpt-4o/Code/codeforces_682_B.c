#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Reading the number of elements

    int *list = (int *)malloc(n * sizeof(int)); // Creating an array to store the elements

    // Reading the elements and adding them to the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    qsort(list, n, sizeof(int), compare); // Sorting the array

    int c = 1; // Initializing the counter variable

    // Iterating through the sorted array to find the smallest missing positive integer
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }

    printf("%d\n", c); // Printing the result

    free(list); // Freeing the allocated memory
    return 0;
}

// <END-OF-CODE>
