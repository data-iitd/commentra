#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000]; // Creating a character array to read the entire line from the console
    scanf("%[^\n]", str); // Reading a line of input from the console and storing it in the character array str
    getchar(); // Consuming the newline character left in the input buffer

    int dotIndex = 0; // Initializing dotIndex variable to 0

    // Finding the index of the last occurrence of '.' character in the string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Checking if the character before the '.' character is '9'
    if (str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n"); // Printing the message if the condition is true
    }

    // Checking if the character after the '.' character is a digit greater than 4
    else if (str[dotIndex + 1] - '0' > 4) {
        char _str[dotIndex]; // Initializing a character array _str to store the substring
        strncpy(_str, str, dotIndex); // Creating a substring of the character array str from the beginning to the index of '.' character
        _str[dotIndex] = '\0'; // Null-terminating the substring

        // Performing integer addition and printing the result
        int num = atoi(_str) + 1;
        printf("%d\n", num);
    }

    // Printing the substring of the character array str from the beginning to the index of '.' character
    else {
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n"); // Printing a newline character at the end of the substring
    }

    return 0;
}
