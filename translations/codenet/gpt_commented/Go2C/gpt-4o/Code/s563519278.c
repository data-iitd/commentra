#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a variable N to hold the number of elements
    int N;
    // Read the integer N from standard input
    scanf("%d", &N);

    // Initialize an array v of size N to hold counts of occurrences
    int *v = (int *)calloc(N, sizeof(int));
    int a;

    // Loop through the range from 1 to N-1 to read N-1 integers
    for (int i = 1; i < N; i++) {
        // Read the next integer from input
        scanf("%d", &a);
        // Increment the count at the index corresponding to the value read (adjusted for 0-based index)
        v[a - 1]++;
    }

    // Loop through the array v to print the counts of occurrences
    for (int i = 0; i < N; i++) {
        // Print each count to the output
        printf("%d\n", v[i]);
    }

    // Free the allocated memory
    free(v);
    return 0;
}

// <END-OF-CODE>
