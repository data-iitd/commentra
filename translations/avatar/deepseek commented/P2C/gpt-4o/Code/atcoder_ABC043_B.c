#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a string to hold the input
    char my_str[100] = "";  // Initialize an empty string to build the result
    int length = 0;  // Variable to keep track of the length of my_str

    // Take a string input from the user
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    
    // Iterate over each character in the input string `s`
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '0' || c == '1') {  // Check if the character is '0' or '1'
            my_str[length] = c;  // Append the character to `my_str`
            length++;  // Increment the length
            my_str[length] = '\0';  // Null-terminate the string
        } else if (c == 'B' && length != 0) {  // Check if the character is 'B' and `my_str` is not empty
            length--;  // Remove the last character from `my_str`
            my_str[length] = '\0';  // Null-terminate the string
        }
    }

    printf("%s\n", my_str);  // Print the content of `my_str`
    return 0;
}

// <END-OF-CODE>
