#include <stdio.h>
#include <string.h>

int main() {
    // Ask the user for a string input
    char s[100]; // Assuming the input string will not exceed 99 characters
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Initialize an empty string variable to store the binary string
    char my_str[100] = "";
    
    // Iterate through each character in the user input string
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        // If the character is '0' or '1', append it to the binary string
        if (c == '0' || c == '1') {
            int len = strlen(my_str);
            my_str[len] = c;
            my_str[len + 1] = '\0'; // Null-terminate the string
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (c == 'B' && strlen(my_str) != 0) {
            my_str[strlen(my_str) - 1] = '\0'; // Remove the last character
        }
    }

    // Print the final binary string
    printf("%s\n", my_str);

    return 0;
}

// <END-OF-CODE>
