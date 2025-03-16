#include <stdio.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    fgets(s, sizeof(s), stdin); // Read the input string

    // Define the difference between lowercase and uppercase ASCII values
    int d = 'a' - 'A';

    // Iterate over each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        char rr = s[i];
        // Check if the character is an uppercase letter
        if ('A' <= s[i] && s[i] <= 'Z') {
            // Convert uppercase to lowercase
            rr = s[i] + d;
        } else if ('a' <= s[i] && s[i] <= 'z') {
            // Convert lowercase to uppercase
            rr = s[i] - d;
        }
        // Print the converted character
        printf("%c", rr);
    }
    printf("\n");
    return 0;
}

// <END-OF-CODE>
