#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a long long type for convenience
typedef long long ll;

// Macros for loop iterations
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

// Macros for input and output
#define in(x) scanf("%d", &x)
#define out(str) printf("%s\n", str)

// Function to update the maximum value
int chmax(int *a, const int *b) { if (*a < *b) { *a = *b; return 1; } return 0; }

// Function to update the minimum value
int chmin(int *a, const int *b) { if (*b < *a) { *a = *b; return 1; } return 0; }

// Global variables for number of strings and their length
int L, N;

int main() {
    // Read the number of strings (N) and the length of each string (L)
    in(N); in(L);

    // Declare an array to hold the strings
    char S[N][L+1];

    // Input the strings from the user
    rep(i, N) scanf("%s", S[i]);

    // Sort the array of strings in lexicographical order
    qsort(S, N, sizeof(char[L+1]), (int (*)(const void *, const void *))strcmp);

    // Output the sorted strings
    rep(i, N) printf("%s", S[i]);

    // Print a newline at the end of the output
    printf("\n");
}
