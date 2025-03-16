
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[100];
    int i = 0;

    // Take a string input from the user
    scanf("%s", s);

    // Initialize an empty string to store the result
    result[0] = '\0';

    // Use a while loop to traverse the string's' until the end
    while (s[i]!= '\0') {
        // Check if the current character is a '.'
        if (s[i] == '.') {
            // If yes, append '0' to the result string
            strcat(result, "0");
        }
        // Move to the next character if it's not a '.'
        else {
            // Increment the index 'i' to move to the next character
            i++;
            // Check if the next character is also a '.'
            if (s[i] == '.') {
                // If yes, append '1' to the result string
                strcat(result, "1");
            }
            // If not, append '2' to the result string
            else {
                strcat(result, "2");
            }
        }
        // Increment the index 'i' to move to the next character
        i++;
    }

    // Print the final result string
    printf("%s", result);

    return 0;
}
