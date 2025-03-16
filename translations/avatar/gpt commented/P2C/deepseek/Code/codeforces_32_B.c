#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[100];
    int i = 0;
    int j = 0;

    // Read input string from the user
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Loop through each character in the input string
    while (i < strlen(s)) {
        // Check if the current character is a dot
        if (s[i] == '.') {
            // If it is a dot, append '0' to the result
            result[j++] = '0';
        } else {
            // If it is not a dot, increment the index to check the next character
            i++;

            // Check the next character
            if (s[i] == '.') {
                // If the next character is a dot, append '1' to the result
                result[j++] = '1';
            } else {
                // If the next character is not a dot, append '2' to the result
                result[j++] = '2';
            }
        }

        // Increment the index to move to the next character in the input string
        i++;
    }

    // Null-terminate the result string
    result[j] = '\0';

    // Print the final result string
    printf("%s\n", result);

    return 0;
}
