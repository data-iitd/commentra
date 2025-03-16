#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input will not exceed 99 characters
    // Read a line from the standard input
    fgets(s, sizeof(s), stdin);

    // Remove the newline character if present
    s[strcspn(s, "\n")] = 0;

    // Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
    const char *result = (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) ? "Yes" : "No";

    // Print the value of the variable result
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
