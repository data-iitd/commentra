#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[100] = "";
    int i = 0;

    // Take a string input from the user
    scanf("%s", s);

    // Use a while loop to traverse the string 's' until the end
    while (i < strlen(s)) {

        // Check if the current character is a '.'
        if (s[i] == '.') {

            // If yes, append '0' to the result string
            strcat(result, "0");

        } else {

            // Move to the next character if it's not a '.'
            i++;

            // Check if the next character is also a '.'
            if (s[i] == '.') {

                // If yes, append '1' to the result string
                strcat(result, "1");

            } else {

                // If not, append '2' to the result string
                strcat(result, "2");

            }

        }

        // Increment the index 'i' to move to the next character
        i++;

    }

    // Print the final result string
    printf("%s\n", result);

    return 0;
}
