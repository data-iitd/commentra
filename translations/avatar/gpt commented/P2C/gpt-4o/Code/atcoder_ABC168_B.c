#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // Define a maximum length for the input string

int main() {
    int K;
    char S[MAX_LENGTH];

    // Read an integer input K from the user
    scanf("%d", &K);
    
    // Read a string input S from the user
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the original string S
        printf("%s\n", S);
    } else {
        // If the length of S is greater than K, print the first K characters followed by '...'
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0;
}

// <END-OF-CODE>
