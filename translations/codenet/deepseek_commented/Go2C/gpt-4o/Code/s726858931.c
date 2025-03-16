#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

<<<<<<< HEAD
// Function to check if a character is present in the string
int isCharPresent(char c, const char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            return 1; // Character found
        }
    }
    return 0; // Character not found
}

int main() {
    char s[MAX_LEN];

    // Read the input string
    scanf("%s", s);

    // Initialize the character to check against the string
    for (char c = 'a'; c <= 'z'; c++) {
        if (!isCharPresent(c, s)) {
            printf("%c\n", c);
            return 0;
        }
    }

    // If no missing character is found, print "None"
    printf("None\n");
=======
// Function to find the first missing character in the alphabet.
void findMissingCharacter(char *s) {
    for (char c = 'a'; c <= 'z'; c++) {
        if (strchr(s, c) == NULL) {
            printf("%c\n", c);
            return;
        }
    }
    printf("None\n");
}

// Main function that executes the program logic.
int main() {
    char s[MAX_LEN];

    // Read the input string.
    scanf("%s", s);

    // Find and print the first missing character.
    findMissingCharacter(s);

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
