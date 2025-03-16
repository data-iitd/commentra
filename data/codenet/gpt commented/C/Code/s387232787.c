#include <stdio.h>

// Array to hold the count of each letter (a-z)
int c[26];

int main(void)
{
    // Declare a string to hold the input
    char str[1200];

    // Read strings from standard input until EOF
    for (; scanf("%s", str) > 0;) {
        // Iterate through each character in the string
        for (char *p = str; *p; p++) {
            // Check if the character is a lowercase letter
            if ('a' <= *p && *p <= 'z') {
                // Increment the count for the corresponding letter
                c[*p - 'a']++;
            } 
            // Check if the character is an uppercase letter
            else if ('A' <= *p && *p <= 'Z') {
                // Increment the count for the corresponding letter (converted to lowercase)
                c[*p - 'A']++;
            }
        }
    }

    // Print the count of each letter from 'a' to 'z'
    for (int i = 0; i < 26; i++) {
        printf("%c : %d\n", 'a' + i, c[i]); 
    }

    return 0; // Indicate that the program ended successfully
}
