#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

void reverse(char *ch) {
    if (islower(*ch)) {
        *ch = toupper(*ch);
    } else {
        *ch = tolower(*ch);
    }
}

int main() {
    char s[1001], t[1001];
    int tmap[MAX_CHAR] = {0};
    int ura = 0, opa = 0;

    // Read input strings
    scanf("%s", s);
    scanf("%s", t);

    // Build frequency map for string t
    for (int i = 0; i < strlen(t); i++) {
        tmap[(unsigned char)t[i]]++;
    }

    int length = strlen(s);

    // First pass: replace characters in s with 'Я' and update tmap
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (tmap[(unsigned char)ch] > 0) {
            tmap[(unsigned char)ch]--;
            if (tmap[(unsigned char)ch] == 0) {
                tmap[(unsigned char)ch] = -1; // Mark as removed
            }
            s[i] = 'Я';
            ura++;
        }
    }

    // Second pass: reverse characters and update tmap
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        reverse(&ch);
        if (tmap[(unsigned char)ch] > 0) {
            tmap[(unsigned char)ch]--;
            if (tmap[(unsigned char)ch] == 0) {
                tmap[(unsigned char)ch] = -1; // Mark as removed
            }
            opa++;
        }
    }

    // Print the results
    printf("%d %d\n", ura, opa);

    return 0;
}

// <END-OF-CODE>
