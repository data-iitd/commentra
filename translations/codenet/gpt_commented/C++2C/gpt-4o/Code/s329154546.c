#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a long long type for convenience
typedef long long ll;

<<<<<<< HEAD
// Global variables for number of strings and their length
int L, N;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

=======
// Macros for loop iterations
#define rep(i, n) for(int i = 0; i < (n); i++)

// Global variables for number of strings and their length
int L, N;

>>>>>>> 98c87cb78a (data updated)
int main() {
    // Read the number of strings (N) and the length of each string (L)
    scanf("%d %d", &N, &L);

    // Declare an array to hold the strings
<<<<<<< HEAD
    char S[N][L + 1]; // +1 for null terminator

    // Input the strings from the user
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }

    // Sort the array of strings in lexicographical order
    qsort(S, N, sizeof(S[0]), compare);

    // Output the sorted strings
    for (int i = 0; i < N; i++) {
        printf("%s", S[i]);
    }
=======
    char S[N][L + 1]; // +1 for the null terminator

    // Input the strings from the user
    rep(i, N) scanf("%s", S[i]);

    // Sort the array of strings in lexicographical order
    qsort(S, N, sizeof(S[0]), (int (*)(const void *, const void *))strcmp);

    // Output the sorted strings
    rep(i, N) printf("%s", S[i]);
>>>>>>> 98c87cb78a (data updated)

    // Print a newline at the end of the output
    printf("\n");

    return 0;
}

// <END-OF-CODE>
