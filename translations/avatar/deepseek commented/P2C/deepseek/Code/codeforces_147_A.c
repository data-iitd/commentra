#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];  // Define a character array to store the input string
    fgets(s, sizeof(s), stdin);  // Read input string from user
    int len = strlen(s);  // Get the length of the input string
    char *res = (char *)malloc(len * sizeof(char));  // Allocate memory for the result array
    int res_index = 0;  // Initialize the index for the result array
    int i;  // Declare a variable for iteration

    // Define a list of punctuation marks
    char punctuation[] = {',', '.', '!', '?'};

    // Iterate over each character in the input string
    for (i = 0; i < len; i++) {
        if (i > 0) {  // Check if it's not the first character
            if (s[i] == ' ') {  // Check if the current character is a space
                if (res[res_index - 1] != ' ') {  // Check if the last character in res is not a space
                    res[res_index++] = s[i];  // Append the current space to res
                }
            } else {  // If the current character is not a space
                int is_punct = 0;  // Flag to check if the current character is a punctuation mark
                for (int j = 0; j < 4; j++) {
                    if (s[i] == punctuation[j]) {
                        is_punct = 1;  // Set the flag if the character is a punctuation mark
                        break;
                    }
                }
                if (is_punct) {  // If the character is a punctuation mark
                    if (res[res_index - 1] == ' ') {  // Check if the last character in res is a space
                        res_index--;  // Remove the last character (space) from res
                    }
                    res[res_index++] = s[i];  // Append the punctuation mark to res
                    res[res_index++] = ' ';  // Append a space after the punctuation mark
                } else {
                    res[res_index++] = s[i];  // Append the character to res if it's not a punctuation mark
                }
            }
        } else {  // For the first character
            if (s[i] == ' ') {  // Check if the first character is a space
                continue;  // Skip the first space
            }
            for (int j = 0; j < 4; j++) {
                if (s[i] == punctuation[j]) {
                    continue;  // Skip the first punctuation mark
                }
            }
            res[res_index++] = s[i];  // Append the first character to res
        }
    }

    // Null-terminate the result string
    res[res_index] = '\0';

    // Print the result string
    printf("%s\n", res);

    // Free the allocated memory
    free(res);

    return 0;
}
