#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements
    int *l = (int *)malloc(n * sizeof(int));  // Allocate memory for the list of elements

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Read the list of elements
    }

    // Initialize variables
    int high = 1;
    int tower = n;
    int maximum = 1;

    // Sort the list
    qsort(l, n, sizeof(int), compare);

    // Loop through the sorted list
    for (int i = 1; i < n; i++) {
        if (l[i] == l[i - 1]) {  // Check if the current element is equal to the previous element
            tower--;  // Decrement the tower count
            high++;  // Increment the high count
        } else {
            if (high > maximum) {  // Check if the current high is greater than the maximum
                maximum = high;  // Update the maximum
            }
            high = 1;  // Reset high to 1
        }
    }

    if (high > maximum) {  // Check if the final high is greater than the maximum
        maximum = high;  // Update the maximum
    }

    // Print the result
    printf("%d %d\n", maximum, tower);

    free(l);  // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
