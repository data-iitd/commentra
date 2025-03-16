#include <stdio.h> // Include headers for input/output operations
#include <stdlib.h> // Include headers for general utilities like memory allocation
<<<<<<< HEAD
#include <stdbool.h> // Include headers for boolean type
#include <string.h> // Include headers for string manipulation

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro for loop operations

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Comparison function for qsort
}
=======
#include <string.h> // Include headers for string manipulation

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro for loop operations
#define all(x) (x), (x + n) // Define a macro for accessing all elements of an array
>>>>>>> 98c87cb78a (data updated)

int main(void) {
    int n;
    scanf("%d", &n); // Read an integer n
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for n integers
<<<<<<< HEAD
    REP(i, n) {
        scanf("%d", &a[i]); // Read n integers into the array a
    }
    
    qsort(a, n, sizeof(int), compare); // Sort the array a
=======
    REP(i, n) scanf("%d", &a[i]); // Read n integers into the array a

    // Sort the array a using qsort
    qsort(a, n, sizeof(int), (int (*)(const void *, const void *))compare);
>>>>>>> 98c87cb78a (data updated)

    REP(i, n - 1) { // Iterate through the sorted array to check for duplicates
        if (a[i] == a[i + 1]) {
            printf("NO\n"); // If duplicates are found, print "NO" and exit
            free(a); // Free allocated memory
            return 0;
        }
    }
<<<<<<< HEAD
    
    printf("YES\n"); // If no duplicates are found, print "YES"
=======
    printf("YES\n"); // If no duplicates are found, print "YES"
    
>>>>>>> 98c87cb78a (data updated)
    free(a); // Free allocated memory
    return 0; // Return 0 to indicate successful execution
}

<<<<<<< HEAD
// <END-OF-CODE>
=======
// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

>>>>>>> 98c87cb78a (data updated)
