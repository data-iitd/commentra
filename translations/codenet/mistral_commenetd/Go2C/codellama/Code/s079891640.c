
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;

    // Read a string input from the standard input using scanf()
    scanf("%s", s);

    // Initialize a for loop to iterate through each character in the string 's'
    for (i = 0; i < strlen(s); i++) {
        // Check if the character at index 'i+1' in the string 's' contains the character at index 'i'
        for (j = i + 1; j < strlen(s); j++) {
            if (s[j] == s[i]) {
                // If the condition is true, print "no" and exit the program
                printf("no\n");
                return 0;
            }
        }
    }

    // If the for loop completes without finding any matching characters, print "yes"
    printf("yes\n");

    return 0;
}

