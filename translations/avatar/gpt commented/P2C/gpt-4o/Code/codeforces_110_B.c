#include <stdio.h>

#define LUCKY "abcd"

int main() {
    // Read an integer input from the user, which determines the length of the output string
    int n;
    scanf("%d", &n);

    // Initialize an empty string to store the result
    char s[n + 1]; // +1 for the null terminator
    s[n] = '\0'; // Null-terminate the string

    // Loop through a range of 'n' to build the output string
    for (int i = 0; i < n; i++) {
        // Append the character from LUCKY based on the current index modulo 4
        // This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
        s[i] = LUCKY[i % 4];
    }

    // Print the final constructed string
    printf("%s\n", s);

    return 0;
}

// <END-OF-CODE>
