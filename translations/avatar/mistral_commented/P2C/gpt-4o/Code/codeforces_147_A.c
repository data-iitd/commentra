#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Take user input as a string 's'
    char s[1000]; // Assuming the input will not exceed 999 characters
    fgets(s, sizeof(s), stdin);

    // Initialize an empty list 'res' to store the final result
    char *res = malloc(1000 * sizeof(char)); // Allocate memory for the result
    int res_index = 0; // Index for the result array

    // Define a string 'punctuation' containing all the punctuation marks
    char punctuation[] = {',', '.', '!', '?'};

    // Iterate through each character 'i' in the string 's'
    for (int i = 0; i < strlen(s); i++) {
        // If current character is a space and previous character is not empty,
        // append the space to the result list
        if (i >= 1) {
            if (s[i] == ' ') {
                if (res_index > 0 && res[res_index - 1] != ' ') {
                    // Append space to the result list
                    res[res_index++] = s[i];
                }
            }
        }

        // If current character is not a space and is a punctuation mark,
        // check if the previous character is empty, if yes then pop the last character from the result list
        // and append the current punctuation mark along with an empty string
        if (strchr(punctuation, s[i]) != NULL) {
            if (res_index > 0 && res[res_index - 1] == ' ') {
                res_index--; // Remove the last space
                res[res_index++] = s[i]; // Append punctuation
                res[res_index++] = ' '; // Append empty string (space)
            } else {
                res[res_index++] = s[i]; // Append punctuation
            }
        } else if (s[i] != ' ') {
            // If current character is not a space and is not a punctuation mark,
            // simply append it to the result list
            res[res_index++] = s[i];
        }
    }

    // Null-terminate the result string
    res[res_index] = '\0';

    // Print the final string
    printf("%s", res);

    // Free allocated memory
    free(res);

    return 0;
}

// <END-OF-CODE>
