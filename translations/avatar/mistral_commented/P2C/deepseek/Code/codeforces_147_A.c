#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    char res[2000] = {0}; // Initialize an empty string 'res' to store the final result
    char punctuation[] = {',', '.', '!', '?'};
    int i, j = 0;

    // Take user input as a string 's'
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;

    // Iterate through each character 'i' in the string 's'
    for (i = 0; i < strlen(s); i++) {
        // If current character is a space and previous character is not empty,
        // append the space to the result list
        if (i > 0) {
            if (s[i] == ' ') {
                if (res[j - 1] != ' ') {
                    res[j++] = s[i];
                }
            }
        }

        // If current character is not a space and is a punctuation mark,
        // check if the previous character is empty, if yes then pop the last character from the result list
        // and append the current punctuation mark along with an empty string
        int is_punctuation = 0;
        for (int k = 0; k < 4; k++) {
            if (s[i] == punctuation[k]) {
                is_punctuation = 1;
                break;
            }
        }
        if (is_punctuation) {
            if (res[j - 1] == ' ') {
                j--;
                res[j++] = s[i];
                res[j++] = ' ';
            } else {
                res[j++] = s[i];
                res[j++] = ' ';
            }
        }

        // If current character is not a space and is not a punctuation mark,
        // simply append it to the result list
        else {
            res[j++] = s[i];
        }
    }

    // Remove trailing space if present
    if (res[j - 1] == ' ') {
        j--;
    }

    // Print the final string
    res[j] = '\0';
    printf("%s\n", res);

    return 0;
}
