#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    // Compare function for qsort to sort in descending order based on the second element
    int second_a = *((int *)a + 1);
    int second_b = *((int *)b + 1);
    return second_b - second_a; // Descending order
}

int main() {
    int n;
    scanf("%d", &n); // Take an integer input representing the number of elements in the list `m`
    
    int (*m)[2] = malloc(n * sizeof(*m)); // Allocate memory for n pairs of integers

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i][0], &m[i][1]); // Create a list of lists `m` where each sublist contains two integers
    }

    qsort(m, n, sizeof(m[0]), compare); // Sort the list `m` in descending order based on the second element of each sublist

    int *a = m[0]; // Assign the first element of the sorted list `m` to the variable `a`

    // Iterate over the rest of the elements in `m` starting from the second element
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) { // Check if the second element of the current element `i` is greater than the second element of the variable `a`
            printf("Happy Alex\n"); // If true, print "Happy Alex" and break out of the loop
            free(m); // Free allocated memory
            return 0; // Exit the program
        }
        a = m[i]; // If false, assign the current element `i` to the variable `a`
    }

    // If the loop completes without breaking
    printf("Poor Alex\n"); // Print "Poor Alex"
    
    free(m); // Free allocated memory
    return 0; // Exit the program
}

// <END-OF-CODE>
