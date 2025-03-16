#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initialize an array of size n to store the input values
    int *a = (int *)malloc(n * sizeof(int));
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array in ascending order
    qsort(a, n, sizeof(int), compare);
    
    // Store the minimum value from the sorted array
    int min = a[0];
    
    // Check if all elements in the array are divisible by the minimum value
    for (int i = 0; i < n; i++) {
        if (a[i] % min != 0) {
            // If any element is not divisible, print -1 and exit
            printf("-1\n");
            free(a);
            return 0;
        }
    }
    
    // If all elements are divisible, print the minimum value
    printf("%d\n", min);
    
    // Free the allocated memory
    free(a);
    
    return 0;
}

// <END-OF-CODE>
