#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    int K;
    char S[100]; // Assuming a maximum length of 99 for the string plus the null terminator

    // Read an integer K from the user
    scanf("%d", &K);

    // Read a string S from the user
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the string S as it is
        printf("%s\n", S);
    } else {
        // If false, truncate the string to the first K characters and append "..."
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0;
}

// <END-OF-CODE>
