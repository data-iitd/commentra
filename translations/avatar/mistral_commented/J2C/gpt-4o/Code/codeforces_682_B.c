#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Reading the number of elements in the list from the input
    int n;
    scanf("%d", &n);

    // Creating an array to store the elements
    int *list = (int *)malloc(n * sizeof(int));

    // Reading 'n' elements from the input and adding them to the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Sorting the array in ascending order using qsort
    qsort(list, n, sizeof(int), compare);

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1;

    // Iterating through the array to find the number of distinct elements
    for (int i = 0; i < n; i++) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if (list[i] >= c) {
            c++;
        }
    }

    // Writing the result to the output
    printf("%d\n", c);

    // Freeing the allocated memory
    free(list);

    return 0;
}

// <END-OF-CODE>
