#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100]; // Declare a variable to hold the input string

    // Read input from the user and store it in the variable 's'
    scanf("%s", s);

    // Get the length of the string
    int len = strlen(s);

    // Iterate over each character in the string 's'
    for (int i = 0; i < len; i++) {
        // Check if the current character exists in the substring that follows it
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                // If the character is found in the remaining substring, print "no" and exit
                printf("no\n");
                return 0;
            }
        }
    }

    // If no duplicate characters were found, print "yes"
    printf("yes\n");
    return 0;
}

// <END-OF-CODE>
