#include <stdio.h>
#include <string.h>

int main() {
    // Read input from the standard input (user input)
    char s[100]; // Assuming the input string will not exceed 99 characters
    fgets(s, sizeof(s), stdin);

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    char *result = (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) ? "Yes" : "No";

    // Print the result indicating whether both 'A' and 'B' were found
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
