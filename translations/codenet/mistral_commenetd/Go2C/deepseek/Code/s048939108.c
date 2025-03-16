#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string starts with "YAKI"
int starts_with_yaki(const char *str) {
    if (strncmp(str, "YAKI", 4) == 0) {
        return 1; // True
    }
    return 0; // False
}

// Main function
int main() {
    char S[1000];

    // Read the first string from the standard input
    scanf("%s", S);

    // Check if the string starts with "YAKI"
    if (starts_with_yaki(S)) {
        printf("Yes\n"); // Print "Yes" if the condition is true
    } else {
        printf("No\n"); // Print "No" if the condition is false
    }

    return 0;
}

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    return (a < b) ? a : b;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    return (a > b) ? a : b;
}
