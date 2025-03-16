#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, x;
    
    // Read the number of elements (n) and the initial value (x) from input
    scanf("%d %d", &n, &x);
    
    // Allocate memory for the array of integers
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array of integers
    qsort(a, n, sizeof(int), compare);
    
    // Initialize the answer counter
    int ans = 0;
    
    // Check if the smallest element in the sorted list is greater than x
    if (a[0] > x) {
        // If true, print 0 and exit since no elements can be subtracted from x
        printf("0\n");
        free(a);
        return 0;
    }
    
    // Iterate through the sorted list of integers
    for (int i = 0; i < n; i++) {
        // If the current element is greater than x, set x to 0 and break the loop
        if (a[i] > x) {
            x = 0;
            break;
        }
        // Subtract the current element from x
        x -= a[i];
        // Increment the answer counter
        ans++;
    }
    
    // If there is any remaining value in x, decrement the answer counter
    if (x != 0) {
        ans--;
    }
    
    // Print the final answer
    printf("%d\n", ans);
    
    // Free the allocated memory
    free(a);
    
    return 0;
}

// <END-OF-CODE>
