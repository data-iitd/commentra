#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
<<<<<<< HEAD
    char s[MAX_LEN];
=======
    char s[MAX_LEN]; // Buffer to hold the input string
>>>>>>> 98c87cb78a (data updated)
    // Read the input string
    scanf("%s", s);

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            printf("%c\n", c);
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    printf("None\n");
    return 0;
}

// <END-OF-CODE>
