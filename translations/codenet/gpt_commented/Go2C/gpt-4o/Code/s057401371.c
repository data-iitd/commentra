#include <stdio.h>

int main() {
    // Create a buffer to store the input string
    char s[100]; // Assuming the input will not exceed 99 characters

    // Read a line of input
    fgets(s, sizeof(s), stdin);

    // Calculate the difference between lowercase and uppercase letters
    int d = 'a' - 'A';

    // Iterate over each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        char rr = s[i];

        // Check if the character is an uppercase letter
        if ('A' <= rr && rr <= 'Z') {
            // Convert uppercase to lowercase by adding the difference
            rr = rr + d;
        } else if ('a' <= rr && rr <= 'z') {
            // Convert lowercase to uppercase by subtracting the difference
            rr = rr - d;
        }

        // Print the modified character
        printf("%c", rr);
    }

    // Print a newline at the end of the output
    printf("\n");

    return 0;
}

// <END-OF-CODE>
