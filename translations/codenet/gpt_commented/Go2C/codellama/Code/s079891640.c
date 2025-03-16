#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;

    // Read input from the user and store it in the variable 's'
    scanf("%s", s);

    // Iterate over each character in the string 's'
    for (i = 0; i < strlen(s); i++) {
        // Check if the current character exists in the substring that follows it
        for (j = i + 1; j < strlen(s); j++) {
            if (s[j] == s[i]) {
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

