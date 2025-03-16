#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    // Initialize an empty string to store the result
    char res[1000] = "";

    // Define a string of punctuation marks to check against
    const char *punctuation = ",.!?";

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the current index is greater than or equal to 1
        if (i > 0) {
            // If the current character is a space
            if (s[i] == ' ') {
                // Only append a space if the last character in res is not a space
                if (res[strlen(res) - 1] != ' ') {
                    strcat(res, " ");
                }
            } else {
                // If the current character is a punctuation mark
                if (strchr(punctuation, s[i])) {
                    // If the last character in res is a space, remove it
                    if (res[strlen(res) - 1] == ' ') {
                        res[strlen(res) - 1] = '\0';
                    }
                    // Append the punctuation mark to the result
                    char punct[2] = {s[i], '\0'};
                    strcat(res, punct);
                    // Append a space after the punctuation
                    strcat(res, " ");
                } else {
                    // If the current character is not punctuation, append it to the result
                    char temp[2] = {s[i], '\0'};
                    strcat(res, temp);
                }
            }
        } else {
            // For the first character, handle it separately
            if (s[i] == ' ') {
                continue;  // Skip if it's a space
            }
            if (strchr(punctuation, s[i])) {
                continue;  // Skip if it's a punctuation mark
            } else {
                // Append the first character to the result if it's not a space or punctuation
                char temp[2] = {s[i], '\0'};
                strcat(res, temp);
            }
        }
    }

    // Print the result
    printf("%s\n", res);

    return 0;
}
