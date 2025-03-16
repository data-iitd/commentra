// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for modulo operation
#define MOD 1000000007

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    // Declare variables for input
<<<<<<< HEAD
    long long N, L;
    
=======
    int N, L;

>>>>>>> 98c87cb78a (data updated)
    // Read the number of strings (N) and the length of strings (L)
    scanf("%lld %lld", &N, &L);

    // Allocate memory for an array of strings
    char **v = (char **)malloc(N * sizeof(char *));
<<<<<<< HEAD
    for (long long i = 0; i < N; i++) {
=======
    for (int i = 0; i < N; i++) {
>>>>>>> 98c87cb78a (data updated)
        v[i] = (char *)malloc((L + 1) * sizeof(char)); // +1 for null terminator
        scanf("%s", v[i]); // Input each string
    }

    // Sort the array of strings
    qsort(v, N, sizeof(char *), compare);

    // Output the sorted strings
<<<<<<< HEAD
    for (long long i = 0; i < N; i++) {
        printf("%s", v[i]); // Print each string in the sorted order
        free(v[i]); // Free the memory allocated for each string
    }
    free(v); // Free the memory allocated for the array of strings
=======
    for (int i = 0; i < N; i++) {
        printf("%s", v[i]); // Print each string in the sorted order
        free(v[i]); // Free the allocated memory for each string
    }
    free(v); // Free the array of string pointers
>>>>>>> 98c87cb78a (data updated)
    printf("\n"); // Print a newline at the end

    return 0;
}

// <END-OF-CODE>
