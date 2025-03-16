#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    char my_str[100] = ""; // Initialize an empty string for the result
    int length = 0; // To keep track of the length of my_str

    // Read input from the user
    fgets(s, sizeof(s), stdin);

    // Iterate through each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Check if the character is '0' or '1'
        if (c == '0' || c == '1') {
            // If it is, append it to the result string
            my_str[length] = c;
            length++;
            my_str[length] = '\0'; // Null-terminate the string
        }
        // Check if the character is 'B' and the result string is not empty
        else if (c == 'B' && length != 0) {
            // If it is, remove the last character from the result string
            length--;
            my_str[length] = '\0'; // Null-terminate the string
        }
    }

    // Print the final result string
    printf("%s\n", my_str);

    return 0;
}

// <END-OF-CODE>
