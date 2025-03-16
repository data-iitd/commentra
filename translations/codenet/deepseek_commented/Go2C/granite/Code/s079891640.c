
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100]; // Variable to store the input string
    fgets(s, sizeof(s), stdin); // Read the input string from standard input

    for (int i = 0; i < strlen(s); i++) { // Iterate over each character in the string
        if (strstr(s + i + 1, &s[i])) { // Check if the character appears again in the substring
            printf("no\n"); // If it does, print "no" and exit
            return 0;
        }
    }

    printf("yes\n"); // If no character appears again, print "yes"
    return 0;
}

