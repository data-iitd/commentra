#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

<<<<<<< HEAD
=======
// Macro definitions for convenience
>>>>>>> 98c87cb78a (data updated)
#define REP(i,n) for(int i=0;i<n;i++) // Repeat macro for loops

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
<<<<<<< HEAD
    // Initialize an array to store the elements and read them from input
    int *a = (int *)malloc(n * sizeof(int));
=======
    // Initialize an array to store the elements
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read elements from input
>>>>>>> 98c87cb78a (data updated)
    REP(i, n) scanf("%d", &a[i]);
    
    // Sort the array to facilitate duplicate checking
    qsort(a, n, sizeof(int), compare);
    
    // Check for duplicates in the sorted array
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            // If a duplicate is found, print "NO" and exit
            printf("NO\n");
            free(a); // Free allocated memory
            return 0;
        }
    }
    
    // If no duplicates are found, print "YES"
    printf("YES\n");
    
    free(a); // Free allocated memory
    return 0; // End of the program
}

// <END-OF-CODE>
