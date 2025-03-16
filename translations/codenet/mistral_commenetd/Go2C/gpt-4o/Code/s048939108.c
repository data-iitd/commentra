#include <stdio.h>
#include <string.h>

// Function to check if a string starts with a given prefix
int startsWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

int main() {
    char S[1000]; // Buffer to hold the input string

    // Read the first string from the standard input
    fgets(S, sizeof(S), stdin);
    
    // Remove the newline character if present
    S[strcspn(S, "\n")] = 0;

    // Check if the string starts with "YAKI"
    if (startsWith(S, "YAKI")) {
        printf("Yes\n"); // Print "Yes" if the condition is true
    } else {
        printf("No\n"); // Print "No" if the condition is false
    }

    return 0;
}

// <END-OF-CODE>
