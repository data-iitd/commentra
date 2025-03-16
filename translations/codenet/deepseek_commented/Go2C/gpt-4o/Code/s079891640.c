#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100]; // Variable to store the input string
    scanf("%s", s); // Read the input string from standard input

    int len = strlen(s); // Get the length of the string

    for (int i = 0; i < len; i++) { // Iterate over each character in the string
        for (int j = i + 1; j < len; j++) { // Check the substring starting from the next character
            if (s[i] == s[j]) { // If the character appears again
                printf("no\n"); // Print "no" and exit
                exit(0);
            }
        }
    }

    printf("yes\n"); // If no character appears again, print "yes"
    return 0;
}
