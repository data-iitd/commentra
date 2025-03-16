#include <stdio.h>
#include <string.h>

int main() {
    // Read input string from the user
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);

    // Initialize an empty string to store the result
    char result[200]; // Result can be longer than input
    int resultIndex = 0;

    // Initialize a counter variable to iterate through the input string
    int i = 0;

    // Loop through each character in the input string
    while (i < strlen(s)) {
        // Check if the current character is a dot
        if (s[i] == '.') {
            // If it is a dot, append '0' to the result
            result[resultIndex++] = '0';
        } else {
            // If it is not a dot, increment the index to check the next character
            i++;

            // Check if we are still within bounds
            if (i < strlen(s)) {
                if (s[i] == '.') {
                    // If the next character is a dot, append '1' to the result
                    result[resultIndex++] = '1';
                } else {
                    // If the next character is not a dot, append '2' to the result
                    result[resultIndex++] = '2';
                }
            }
        }

        // Increment the index to move to the next character in the input string
        i++;
    }

    // Null-terminate the result string
    result[resultIndex] = '\0';

    // Print the final result string
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
