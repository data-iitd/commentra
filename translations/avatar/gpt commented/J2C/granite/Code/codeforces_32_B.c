
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation

int main() {
    // Declare a character array to store the input string
    char n[100];
    
    // Read a string input and store it in the character array
    scanf("%s", n);
    
    // Declare a boolean variable to track the state of the previous character
    int s = 0;
    
    // Iterate through each character in the character array
    for (int i = 0; i < strlen(n); i++) {
        // Check if the current character is a dot '.'
        if (n[i] == '.') {
            // If the previous character was also a dot, print 1 and reset the state
            if (s) {
                printf("1");
                s = 0; // Resetting the state
            } else {
                // If the previous character was not a dot, print 0
                printf("0");
            }
        } else {
            // If the current character is not a dot
            if (s) {
                // If the previous character was also not a dot, print 2 and reset the state
                printf("2");
                s = 0; // Resetting the state
            } else {
                // If the previous character was a dot, set the state to true
                s = 1;
            }
        }
    }
    
    // End the program
    return 0;
}
