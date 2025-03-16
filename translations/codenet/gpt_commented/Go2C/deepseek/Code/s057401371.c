#include <stdio.h>

int main() {
    char s[1000];
    int d = 'a' - 'A';
    int i = 0;

    // Read the next line of input
    while ((s[i] = getchar()) != '\n') {
        i++;
    }
    s[i] = '\0'; // Null-terminate the string

    // Iterate over each character in the input string
    for (i = 0; s[i] != '\0'; i++) {
        char r = s[i];

        // Check if the character is an uppercase letter
        if (r >= 'A' && r <= 'Z') {
            // Convert uppercase to lowercase by adding the difference
            r = r + d;
        } else if (r >= 'a' && r <= 'z') {
            // Convert lowercase to uppercase by subtracting the difference
            r = r - d;
        }

        // Print the modified character
        putchar(r);
    }

    // Print a newline at the end of the output
    putchar('\n');

    return 0;
}
