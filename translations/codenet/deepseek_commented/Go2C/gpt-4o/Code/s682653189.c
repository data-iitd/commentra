#include <stdio.h>

int main() {
    // Declare a string variable to store the input
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    
    // Read a string input from the user and store it in `s`
    scanf("%s", s);
    
    // Iterate over each character in the string `s` and print 'x' for each character
    for (int i = 0; s[i] != '\0'; i++) {
        printf("x");
    }
    
    // Print a newline character to move to the next line
    printf("\n");
    
    return 0;
}

// <END-OF-CODE>
