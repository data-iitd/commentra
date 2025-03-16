#include <stdio.h> // Including standard input-output library
#include <stdbool.h> // Including library for boolean type

int main() {
    // Declaring a character array to hold the input string
    char n[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    // Reading a string input from the console
    scanf("%s", n);
    
    // Initializing a boolean variable to track the state of the previous character
    bool s = false;
    
    // Iterating through each character in the character array
    for (int i = 0; n[i] != '\0'; i++) {
        // Checking if the current character is a dot '.'
        if (n[i] == '.') {
            // If the previous character was also a dot, print 1 and reset the state
            if (s) {
                printf("1");
                s = false; // Resetting the state
            } else {
                // If the previous character was not a dot, print 0
                printf("0");
            }
        } else {
            // If the current character is not a dot
            if (s) {
                // If the previous character was also not a dot, print 2 and reset the state
                printf("2");
                s = false; // Resetting the state
            } else {
                // If the previous character was a dot, set the state to true
                s = true;
            }
        }
    }
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
