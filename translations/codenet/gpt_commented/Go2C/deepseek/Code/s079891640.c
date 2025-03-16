#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declare a character array to hold the input string
    scanf("%s", s); // Read input from the user and store it in the array 's'

    // Iterate over each character in the string 's'
    for (int i = 0; i < strlen(s); i++) {
        // Check if the current character exists in the substring that follows it
        for (int j = i + 1; j < strlen(s); j++) {
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
