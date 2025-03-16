#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    
    // Read the number of elements
    scanf("%d", &n);
    
    // Allocate memory for the list of elements
    int *l = (int *)malloc(n * sizeof(int));
    
    // Read the list of elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    // Sort the list
    qsort(l, n, sizeof(int), compare);
    
    // Initialize variables
    int c = 0;  // Counter variable

    // Iterate through the list to find the maximum number of unique elements
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;  // Increment the counter if the current element is greater than the counter
        }
    }

    // Print the result
    printf("%d\n", c + 1);  // Print the maximum number of unique elements

    // Free allocated memory
    free(l);
    
    return 0;
}

// <END-OF-CODE>
