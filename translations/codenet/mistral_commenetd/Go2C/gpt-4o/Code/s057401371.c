// Importing required headers
#include <stdio.h>  // For standard input and output
#include <stdlib.h> // For general utilities

int main() {
    // Declaring a string to hold the input
    char s[1000]; // Assuming the input will not exceed 999 characters

    // Reading the first line from standard input and storing it in the string 's'
    fgets(s, sizeof(s), stdin);

    // Declaring and initializing a variable 'd' with the value of 'a' - 'A'
    int d = 'a' - 'A';

    // Iterating through each character in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        char rr = s[i];

        // Checking if the current character is an uppercase letter
        if ('A' <= rr && rr <= 'Z') {
            // If yes, adding the value of 'd' to 'rr'
            rr = rr + d;
        } else if ('a' <= rr && rr <= 'z') {
            // If no, subtracting the value of 'd' from 'rr'
            rr = rr - d;
        }

        // Printing the transformed character 'rr' to the standard output
        printf("%c", rr);
    }

    // Printing a newline character after the transformation is complete
    printf("\n");

    return 0;
}

// <END-OF-CODE>
