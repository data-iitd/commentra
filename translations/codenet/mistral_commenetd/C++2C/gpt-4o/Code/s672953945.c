#include <stdio.h>      // Standard input/output library
#include <stdlib.h>     // Standard library for memory allocation
#include <string.h>     // String handling library
#include <stdbool.h>    // Boolean type library

#define MAX_STRINGS 1000 // Maximum number of strings
#define MAX_LENGTH 100   // Maximum length of each string

// The main function begins here
int main() {
    // Initialize an array of strings
    char v[MAX_STRINGS][MAX_LENGTH];

    // Read the number of strings 'N' and their lengths 'L' from the standard input
    int N, L;
    scanf("%d %d", &N, &L);

    // Allocate memory for 'N' strings in the array 'v'
    for (int i = 0; i < N; i++) {
        // Read a string 's' from the standard input and store it in the array 'v'
        scanf("%s", v[i]);
    }

    // Sort the strings in the array 'v' using qsort
    qsort(v, N, sizeof(v[0]), (int (*)(const void *, const void *)) strcmp);

    // Iterate through the sorted strings in the array 'v' and print each string to the standard output
    for (int i = 0; i < N; i++) {
        // Print the current string from the array 'v' to the standard output
        printf("%s", v[i]);
    }

    // Print a newline character at the end of the output
    printf("\n");

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
