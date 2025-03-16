#include <stdio.h>

#define LUCKY "abcd"

int main() {
    int n;
    // Ask the user to input an integer n
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Initialize an empty string s
    char s[100]; // Assuming the maximum length of s will not exceed 100 characters
    s[0] = '\0'; // Initialize the string to be empty

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Add the character at index i % 4 of the string LUCKY to the string s
        char ch = LUCKY[i % 4];
        int len = strlen(s);
        s[len] = ch; // Append the character to the string
        s[len + 1] = '\0'; // Null-terminate the string
    }

    // Print the final string s
    printf("%s\n", s);

    return 0;
}

// <END-OF-CODE>
