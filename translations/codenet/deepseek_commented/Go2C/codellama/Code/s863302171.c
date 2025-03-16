#include <stdio.h>

int main() {
    // Declare a variable to store the input string
    char n[100];
    
    // Read a string input from the user and store it in `n`
    scanf("%s", n);
    
    // Loop through the first three characters of the input string
    for (int i = 0; i < 3; i++) {
        // Check if the character at the current position is '7'
        if (n[i] == '7') {
            // If '7' is found, print "Yes" and exit the program
            printf("Yes\n");
            return 0;
        }
    }
    
    // If the loop completes without finding a '7', print "No"
    printf("No\n");
    
    return 0;
}
