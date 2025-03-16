#include <stdio.h> // Include standard input-output header for basic I/O functions
#include <stdlib.h> // Include standard library header for general utilities
#include <string.h> // Include string header for string manipulation
#include <limits.h> // Include limits header for numeric limits
<<<<<<< HEAD
#include <stdbool.h> // Include stdbool header for boolean type
#include <ctype.h> // Include ctype header for character handling functions
=======
>>>>>>> 98c87cb78a (data updated)

#define MAX_STRINGS 100 // Define a maximum number of strings
#define MAX_LENGTH 100 // Define a maximum length for each string

int main() {
    int N, L; // Declare variables for the number of strings and the length of each string
    scanf("%d %d", &N, &L); // Read the number of strings and the length of each string

<<<<<<< HEAD
    char S[MAX_STRINGS][MAX_LENGTH + 1]; // Declare a 2D array to store the strings

=======
    char S[MAX_STRINGS][MAX_LENGTH + 1]; // Declare a 2D array to store the strings (+1 for null terminator)
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]); // Read each string and store it in the array
    }

    // Sort the array of strings using qsort
    qsort(S, N, sizeof(S[0]), (int (*)(const void *, const void *)) strcmp);

    for (int i = 0; i < N; i++) {
        printf("%s", S[i]); // Output each sorted string
    }
    printf("\n"); // Output a newline character

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
