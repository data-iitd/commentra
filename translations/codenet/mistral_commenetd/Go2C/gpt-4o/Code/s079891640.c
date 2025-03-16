#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare a variable named 's' of type char array
char s[100];

int main() {
    // Read a string input from the standard input
    scanf("%s", s);

    // Initialize a for loop to iterate through each character in the string 's'
    for (int i = 0; i < strlen(s); i++) {
        // Check if the character at index 'i+1' in the string 's' contains the character at index 'i'
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[j] == s[i]) {
                // If the condition is true, print "no" and exit the program
                printf("no\n");
                exit(0);
            }
        }
    }

    // If the for loop completes without finding any matching characters, print "yes"
    printf("yes\n");
    
    return 0;
}

// <END-OF-CODE>
