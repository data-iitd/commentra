#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[100]; // Variable to store the input string
    scanf("%s", s); // Read the input string from standard input

    for (int i = 0; i < strlen(s); i++) { // Iterate over each character in the string
        for (int j = i + 1; j < strlen(s); j++) { // Check if the character appears again in the substring
            if (s[i] == s[j]) { // If it does, print "no" and exit
                printf("no\n");
                return 0;
            }
        }
    }

    printf("yes\n"); // If no character appears again, print "yes"
    return 0;
}
