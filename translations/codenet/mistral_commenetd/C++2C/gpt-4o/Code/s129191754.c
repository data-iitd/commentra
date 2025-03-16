#include <stdio.h>
#include <stdlib.h>

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro REP for repetition

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Comparison function for qsort
}

int main(void) { // The main function
    int n;
    scanf("%d", &n); // Read the number of elements in the array

    // Initialize an array of size n
    int *a = (int *)malloc(n * sizeof(int));

    // Read the elements of the array
    REP(i, n) scanf("%d", &a[i]);

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), compare);

    // Check if there are any consecutive elements in the sorted array
    REP(i, n - 1) {
        // If there are consecutive elements, print "NO" and exit the program
        if (a[i] == a[i + 1]) {
            printf("NO\n");
            free(a); // Free allocated memory
            return 0;
        }
    }

    // If no consecutive elements were found, print "YES"
    printf("YES\n");

    free(a); // Free allocated memory
    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
