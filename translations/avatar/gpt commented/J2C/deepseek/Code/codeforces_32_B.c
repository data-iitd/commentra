#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaring a character array to read input from the console
    char n[1000];
    
    // Reading a string input and storing it in the character array
    scanf("%s", n);
    
    // Initializing a boolean variable to track the state of the previous character
    int s = 0;
    
    // Iterating through each character in the character array
    for (int i = 0; n[i] != '\0'; i++) {
        // Checking if the current character is a dot '.'
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
                // If the previous character was a dot, set the state to 1
                s = 1;
            }
        }
    }
    
    // End of the program
    return 0;
}
