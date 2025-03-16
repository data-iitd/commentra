#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse the given character
char reverse(char ch) {
    if (islower(ch)) {
        return toupper(ch);
    } else {
        return tolower(ch);
    }
}

int main() {
    char s[100];
    char t[100];
    int ura = 0;
    int opa = 0;
    int tmap[256] = {0}; // Array to store the frequency of each character in the second string

    // Read the first input string from the console
    scanf("%s", s);
    // Read the second input string from the console
    scanf("%s", t);

    // Read the characters of the second string and store their frequencies in the tmap array
    for (int i = 0; i < strlen(t); i++) {
        tmap[(unsigned char)t[i]]++;
    }

    // Process the first string
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (tmap[(unsigned char)ch] > 0) {
            tmap[(unsigned char)ch]--;
            s[i] = 'Я';
            ura++;
        }
    }

    // Process the reversed version of the first string
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        char rch = reverse(ch);
        if (tmap[(unsigned char)rch] > 0) {
            tmap[(unsigned char)rch]--;
            opa++;
        }
    }

    // Print the results
    printf("%d %d\n", ura, opa);

    return 0;
}
