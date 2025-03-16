#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000]; // Assuming the input string will not exceed 999 characters
    fgets(s, sizeof(s), stdin); // Read a line of input
    int length = strlen(s);
    char ch = 0;

    // Iterate from the end of the string to find the last non-space, non-'?' character
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') {
            ch = s[i];
            break;
        }
    }

    ch = tolower(ch); // Convert to lowercase

    // Check if the character is a vowel or 'y'
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
