
#include <stdio.h>

int main() {
    // Declare a string variable to store the input
    char s[100];
    
    // Read a string input from the user and store it in `s`
    scanf("%s", s);
    
    // Iterate over each character in the string `s` and print 'x' for each character
    for (int i = 0; i < strlen(s); i++) {
        printf("x");
    }
    
    // Print a newline character to move to the next line
    printf("\n");
    
    return 0;
}
