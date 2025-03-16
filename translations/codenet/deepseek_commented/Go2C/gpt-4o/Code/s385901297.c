#include <stdio.h>  // Importing the standard I/O library
#include <stdlib.h> // Importing the standard library for memory allocation and sorting
#include <stdbool.h> // Importing the boolean library for true/false values

<<<<<<< HEAD
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Comparison function for qsort
=======
// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int ns[4]; // Create an array of integers with a length of 4

    // Read four integers from standard input
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

<<<<<<< HEAD
    qsort(ns, 4, sizeof(int), compare); // Sort the array ns in ascending order
=======
    // Sort the array ns in ascending order
    qsort(ns, 4, sizeof(int), compare);
>>>>>>> 98c87cb78a (data updated)

    // Check if the sorted array ns contains the numbers 1, 4, 7, and 9 in that order
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("YES\n"); // Print "YES" if the condition is true
    } else {
        printf("NO\n"); // Print "NO" if the condition is false
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
