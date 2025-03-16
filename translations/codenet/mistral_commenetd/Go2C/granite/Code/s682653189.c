
#include <stdio.h>

int main() {
    // Initialize a variable "s" of type string.
    char s[100];

    // Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
    scanf("%s", s);

    // Iterate through each character in the string "s" using a for loop.
    for (int i = 0; i < strlen(s); i++) {
        // Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
        printf("x");
    }

    // Print a newline character to the standard output.
    printf("\n");

    // Indicate the end of the code.
    return 0;
}
