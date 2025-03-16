#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1000];  // Input string buffer
    char res[1000];  // Result buffer
    int res_index = 0;  // Index for the result buffer
    char punctuation[] = {',', '.', '!', '?', '\0'};  // Define punctuation marks

    // Take input string from user
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);

    // Iterate over each character in the input string
    for (int i = 0; i < len; i++) {
        if (i >= 1) {  // Check if it's not the first character
            if (s[i] == ' ') {  // Check if the current character is a space
                if (res_index > 0 && res[res_index - 1] != ' ') {  // Check if the last character in res is not a space
                    res[res_index++] = s[i];  // Append the current space to res
                }
            } else {  // If the current character is not a space
                bool is_punctuation = false;
                for (int j = 0; punctuation[j] != '\0'; j++) {
                    if (s[i] == punctuation[j]) {  // Check if the current character is a punctuation mark
                        is_punctuation = true;
                        break;
                    }
                }
                if (is_punctuation) {  // If it's a punctuation mark
                    if (res_index > 0 && res[res_index - 1] == ' ') {  // Check if the last character in res is a space
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
            bool is_punctuation = false;
            for (int j = 0; punctuation[j] != '\0'; j++) {
                if (s[i] == punctuation[j]) {  // Check if the first character is a punctuation mark
                    is_punctuation = true;
                    break;
                }
            }
            if (!is_punctuation) {
                res[res_index++] = s[i];  // Append the first character to res
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
