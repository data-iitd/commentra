#include <stdio.h>      // Including standard input-output library
#include <stdlib.h>     // Including standard library for memory allocation and conversion
#include <string.h>     // Including string library for string manipulation

int main() {
    char str[100]; // Creating a character array to store the input string
    int dotIndex = -1; // Initializing dotIndex variable to -1

    // Reading a line of input from the console and storing it in the character array str
    fgets(str, sizeof(str), stdin);

    // Finding the index of the last occurrence of '.' character in the string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i; // Update dotIndex when '.' is found
        }
    }

    // Checking if the character before the '.' character is '9'
    if (dotIndex > 0 && str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n"); // Printing the message if the condition is true
    }
    // Checking if the character after the '.' character is a digit greater than 4
    else if (dotIndex + 1 < strlen(str) && str[dotIndex + 1] >= '0' && str[dotIndex + 1] <= '9' && (str[dotIndex + 1] - '0') > 4) {
        char _str[100]; // Initializing an empty string variable _str
        strncpy(_str, str, dotIndex); // Creating a substring of the character array str from the beginning to the index of '.' character
        _str[dotIndex] = '\0'; // Null-terminating the substring

        // Converting the substring to an integer, adding 1, and printing the result
        long long number = atoll(_str); // Convert string to long long
        printf("%lld\n", number + 1); // Print the incremented value
    }
    // Printing the substring of the character array str from the beginning to the index of '.' character
    else {
        for (int i = 0; i < dotIndex; i++) {
            putchar(str[i]); // Print each character before the dot
        }
        putchar('\n'); // Printing a newline character at the end of the substring
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
