#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_CHAR 256

// Function to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    // Declare variables
    char s[MAX_LENGTH], t[MAX_LENGTH];
    int tmap[MAX_CHAR] = {0}; // Frequency map for characters in string t
    int ura = 0; // Unique characters replaced
    int opa = 0; // Reversed characters

    // Read the first string
    scanf("%s", s);
    // Read the second string
    scanf("%s", t);

    // Populate the character frequency map for string t
    for (int i = 0; i < strlen(t); i++) {
        tmap[(unsigned char)t[i]]++;
    }

    // Get the length of the first string
    int length = strlen(s);

    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        int num = tmap[(unsigned char)ch];
        // If the character is not in the map, skip it
        if (num == 0) continue;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1) {
            tmap[(unsigned char)ch] = 0;
        } else {
            tmap[(unsigned char)ch]--;
        }
        // Replace the character in the string with 'Я'
        s[i] = 'Я';
        // Increment the unique character replacement counter
        ura++;
    }

    // Second pass: Check for reversed characters and update the frequency map
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = reverse(ch);
        int num = tmap[(unsigned char)rch];
        // If the reversed character is not in the map, skip it
        if (num == 0) continue;
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (num == 1) {
            tmap[(unsigned char)rch] = 0;
        } else {
            tmap[(unsigned char)rch]--;
        }
        // Increment the reversed character counter
        opa++;
    }

    // Output the counts of unique character replacements and reversed characters
    printf("%d %d\n", ura, opa);

    return 0;
}

// <END-OF-CODE>
