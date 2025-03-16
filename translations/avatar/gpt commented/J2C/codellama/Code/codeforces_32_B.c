#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // Creating a character array to store the input string
    char n[100];
    
    // Reading a string input and storing it in the character array
    scanf("%s", n);
    
    // Initializing a boolean variable to track the state of the previous character
    bool s = false;
    
    // Iterating through each character in the character array
    for (int i = 0; i < strlen(n); i++) {
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
    
    // Printing the end of code comment
    printf("