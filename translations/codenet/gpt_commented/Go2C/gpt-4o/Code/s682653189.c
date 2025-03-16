#include <stdio.h>

int main() {
    // Declare a variable to hold the input string
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    
    // Read a string input from the user
    scanf("%s", s);
    
    // Loop through each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        // Print 'x' for each character in the input string
        printf("x");
    }
    
    // Print a newline after printing all 'x's
    printf("\n");
    
    return 0;
}

// <END-OF-CODE>
