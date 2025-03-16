#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to reverse the case of a character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    char s[MAX_LENGTH], t[MAX_LENGTH];
    int ura = 0, opa = 0;
    int tmap[256] = {0}; // Frequency map for characters in the second string

    // Read the first and second strings
    scanf("%s", s);
    scanf("%s", t);

    // Fill the frequency map for the second string
    for (int i = 0; t[i] != '\0'; i++) {
        tmap[(unsigned char)t[i]]++;
    }

    // Process the first string
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (tmap[(unsigned char)ch] > 0) {
            if (tmap[(unsigned char)ch] == 1) {
                tmap[(unsigned char)ch]--;
            } else {
                tmap[(unsigned char)ch]--;
            }
            s[i] = 'Я'; // Replace the character with 'Я'
            ura++;
        }
    }

    // Process the reversed version of the first string
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        char rch = reverse(ch);
        if (tmap[(unsigned char)rch] > 0) {
            if (tmap[(unsigned char)rch] == 1) {
                tmap[(unsigned char)rch]--;
            } else {
                tmap[(unsigned char)rch]--;
            }
            opa++;
        }
    }

    // Print the results
    printf("%d %d\n", ura, opa);

    return 0;
}
