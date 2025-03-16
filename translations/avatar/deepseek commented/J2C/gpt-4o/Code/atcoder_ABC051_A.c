#include <stdio.h> // Including standard input-output library
#include <string.h> // Including string library for string manipulation

int main() { // Main function is the entry point of the program
    char a[1000]; // Declaring a character array to hold the input string
    fgets(a, sizeof(a), stdin); // Reading a line of input from the user

    // Replacing commas with spaces in the input string
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            a[i] = ' '; // Replace comma with space
        }
    }

    printf("%s", a); // Printing the manipulated string
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
