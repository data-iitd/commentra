#include <stdio.h>   // Include header for standard input/output functions
#include <stdlib.h>  // Include header for the qsort function

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Compare two integers
}

int main() {
    int s[10], i; // Declare an array to store the input numbers and a variable for the loop

    // Step 3: Read input numbers into the array
    for(i = 0; i < 10; i++) {
        scanf("%d", &s[i]); // Read input and store it in the array
    }

    // Step 4: Sort the array
    qsort(s, 10, sizeof(int), compare); // Sort the array in ascending order

    // Step 5: Print the last four numbers of the sorted array
    for(i = 9; i > 6; i--) {
        printf("%d\n", s[i]); // Print the last four numbers
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
