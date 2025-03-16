#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    // Read the number of integers
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read the integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array
    qsort(a, n, sizeof(int), compare);
    
    // Check if any element is not divisible by the first element
    int first = a[0];
    int divisible = 1; // Assume all are divisible initially
    
    for (int i = 1; i < n; i++) {
        if (a[i] % first != 0) {
            divisible = 0; // Found an element not divisible
            break;
        }
    }
    
    // Print the result
    if (divisible) {
        printf("%d\n", first);
    } else {
        printf("-1\n");
    }
    
    // Free the allocated memory
    free(a);
    
    return 0;
}

// <END-OF-CODE>
