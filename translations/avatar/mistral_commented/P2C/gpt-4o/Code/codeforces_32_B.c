#include <stdio.h>
#include <string.h>

int main() {
    // Take a string input from the user
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);

    // Initialize an empty string to store the result
    char result[200]; // Result can be longer than input
    int resultIndex = 0;

    // Initialize a variable 'i' to traverse the string 's'
    int i = 0;

    // Use a while loop to traverse the string 's' until the end
    while (i < strlen(s)) {
        // Check if the current character is a '.'
        if (s[i] == '.') {
            // If yes, append '0' to the result string
            result[resultIndex++] = '0';
        } else {
            // Move to the next character if it's not a '.'
            i++;

            // Check if the next character is also a '.'
            if (s[i] == '.') {
                // If yes, append '1' to the result string
                result[resultIndex++] = '1';
            } else {
                // If not, append '2' to the result string
                result[resultIndex++] = '2';
            }
        }
        // Increment the index 'i' to move to the next character
        i++;
    }

    // Null-terminate the result string
    result[resultIndex] = '\0';

    // Print the final result string
    printf("%s\n", result);

    return 0;
}
// <END-OF-CODE>
