#include <stdio.h>
#include <stdlib.h>

// Define the main function, taking no arguments
void main() {

    // Declare variables to store the input values
    int K;
    char S[1000];

    // Read the integer K from the standard input
    scanf("%d", &K);

    // Read a string S from the standard input
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {

        // If the condition is true, print the string S
        printf("%s", S);

    } else {

        // If the condition is false, print a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...");
    }
}

