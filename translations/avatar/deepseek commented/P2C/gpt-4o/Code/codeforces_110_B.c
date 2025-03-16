#include <stdio.h>

#define LUCKY "abcd"
// Define a string LUCKY containing the characters "abcd"

int main() {
    int n;
    scanf("%d", &n);
    // Take an integer input n from the user

    char s[100]; // Initialize a string s to store the result (assuming max length of 100)
    s[0] = '\0'; // Initialize the string to be empty

    for (int i = 0; i < n; i++) {
        // Loop n times to construct the string s
        char ch = LUCKY[i % 4];
        // Get a character from LUCKY based on the index i modulo 4
        int len = strlen(s);
        s[len] = ch; // Append the character to s
        s[len + 1] = '\0'; // Null-terminate the string
    }

    printf("%s\n", s);
    // Print the final string s

    return 0;
}
