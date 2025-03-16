
#include <stdio.h>
#include <string.h>

// Define the main function, taking no arguments
int main() {

    // Read the integer K from the standard input
    int K;
    scanf("%d", &K);

    // Read a string S from the standard input
    char S[10000];
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {

        // If the condition is true, return the string S
        printf("%s", S);
    }

    // If the condition is false, return a slice of the string S
    // from the beginning to the index K, followed by three dots '...'
    else {
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...");
    }

    // Return success
    return 0;
}

