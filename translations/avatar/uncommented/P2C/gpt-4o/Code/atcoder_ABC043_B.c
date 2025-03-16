#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    char my_str[100] = ""; // Initialize an empty string for my_str
    int len = 0; // Length of my_str

    // Read input string
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove the newline character if present

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '0' || c == '1') {
            my_str[len] = c; // Add character to my_str
            len++; // Increase the length
            my_str[len] = '\0'; // Null-terminate the string
        } else if (c == 'B' && len != 0) {
            len--; // Decrease the length
            my_str[len] = '\0'; // Null-terminate the string
        }
    }

    printf("%s\n", my_str); // Print the resulting string
    return 0;
}

// <END-OF-CODE>
