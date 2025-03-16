#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Initialize an array to store the input integers
    int *list = (int *)malloc(n * sizeof(int));
    
    // Read n integers from input and add them to the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    
    // Sort the list of integers in ascending order
    qsort(list, n, sizeof(int), compare);
    
    // Initialize a counter to track the maximum consecutive integer
    int c = 1;
    
    // Iterate through the sorted list to find the maximum consecutive integer
    for (int i = 0; i < n; i++) {
        // If the current integer is greater than or equal to the counter, increment the counter
        if (list[i] >= c) {
            c++;
        }
    }
    
    // Print the result which is the maximum consecutive integer found
    printf("%d\n", c);
    
    // Free the allocated memory
    free(list);
    
    return 0;
}

// <END-OF-CODE>
