#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[4]; // "Yes" or "No" with null terminator

    // Read input from the standard input (user input)
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    if (strstr(s, "A") != NULL && strstr(s, "B") != NULL) {
        strcpy(result, "Yes");
    } else {
        strcpy(result, "No");
    }

    // Print the result indicating whether both 'A' and 'B' were found
    printf("%s\n", result);

    return 0;
}
