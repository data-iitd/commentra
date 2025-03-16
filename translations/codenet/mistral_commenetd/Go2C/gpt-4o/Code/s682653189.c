#include <stdio.h>

int main() {
    // Initialize a variable "s" of type char array (string).
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator.

    // Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
    scanf("%s", s);

    // Iterate through each character in the string "s" using a for loop.
    for (int i = 0; s[i] != '\0'; i++) {
        // Print the character 'x' to the standard output (usually the terminal).
        printf("x");
    }

    // Print a newline character to the standard output.
    printf("\n");

    // Indicate the end of the code.
    return 0;
}

// <END-OF-CODE>
