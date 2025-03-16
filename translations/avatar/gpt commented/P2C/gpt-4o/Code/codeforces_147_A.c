#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Take input from the user
    char s[1000]; // Assuming a maximum input length of 999 characters
    fgets(s, sizeof(s), stdin);

    // Initialize an empty string to store the result
    char res[2000]; // Result can be larger than input
    int res_index = 0;

    // Define a list of punctuation marks to check against
    char punctuation[] = {',', '.', '!', '?'};

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the current index is greater than or equal to 1
        if (i >= 1) {
            // If the current character is a space
            if (s[i] == ' ') {
                // Only append a space if the last character in res is not a space
                if (res_index > 0 && res[res_index - 1] != ' ') {
                    res[res_index++] = ' ';
                }
            } else {
                // If the current character is a punctuation mark
                int is_punctuation = 0;
                for (int j = 0; j < sizeof(punctuation); j++) {
                    if (s[i] == punctuation[j]) {
                        is_punctuation = 1;
                        break;
                    }
                }
                if (is_punctuation) {
                    // If the last character in res is a space, remove it
                    if (res_index > 0 && res[res_index - 1] == ' ') {
                        res_index--;
                    }
                    // Append the punctuation mark to the result
                    res[res_index++] = s[i];
                    // Append a space after the punctuation
                    res[res_index++] = ' ';
                } else {
                    // If the current character is not punctuation, append it to the result
                    res[res_index++] = s[i];
                }
            }
        } else {
            // For the first character, handle it separately
            if (s[i] != ' ' && s[i] != ',' && s[i] != '.' && s[i] != '!' && s[i] != '?') {
                // Append the first character to the result if it's not a space or punctuation
                res[res_index++] = s[i];
            }
        }
    }

    // Null-terminate the result string
    res[res_index] = '\0';

    // Print the result
    printf("%s", res);

    return 0;
}

// <END-OF-CODE>
