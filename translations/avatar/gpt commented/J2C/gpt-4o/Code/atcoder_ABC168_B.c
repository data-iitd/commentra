#include <stdio.h> // Include standard input-output library
#include <string.h> // Include string library for string manipulation

int main() {
    // Declare variables
    int K;
    char S[100]; // Assuming the maximum length of the string is 99 characters + 1 for null terminator

    // Read an integer K from the user
    scanf("%d", &K);
    
    // Read a string S from the user
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the string S as it is
        printf("%s\n", S);
    } else {
        // If false, print the first K characters of S followed by "..."
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
