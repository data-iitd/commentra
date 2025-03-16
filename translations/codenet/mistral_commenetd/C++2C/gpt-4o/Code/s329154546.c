#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100 // Define a maximum number of strings
#define MAX_LENGTH 100 // Define a maximum length for each string

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b); // Comparison function for qsort
}

int main() { // Main function
    int L, N; // Declare variables for the length of the string and the number of strings
    scanf("%d %d", &N, &L); // Read the number of strings and their length from the user
    char S[MAX_STRINGS][MAX_LENGTH]; // Declare a 2D array of strings 'S' of size 'N' and length 'L'
    
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]); // Read each string from the user and store it in the array 'S'
    }
    
    qsort(S, N, sizeof(S[0]), compare); // Sort the strings in ascending order using qsort
    
    for (int i = 0; i < N; i++) {
        printf("%s", S[i]); // Print each sorted string to the console
    }
    
    printf("\n"); // Print an empty line at the end
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
