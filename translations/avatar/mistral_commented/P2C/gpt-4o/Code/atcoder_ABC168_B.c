#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // Define a maximum length for the string

// Define the main function
int main() {
    int K;
    char S[MAX_LENGTH];

    // Read the integer K from the standard input
    scanf("%d", &K);
    // Read a string S from the standard input
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If the condition is true, print the string S
        printf("%s\n", S);
    } else {
        // If the condition is false, print a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0;
}

// <END-OF-CODE>
