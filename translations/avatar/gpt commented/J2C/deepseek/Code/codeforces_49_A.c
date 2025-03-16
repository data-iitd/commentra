#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    char ch = 0;

    // Read a line of input from the user
    fgets(s, sizeof(s), stdin);

    // Get the length of the input string
    int length = strlen(s);

    // Loop through the string in reverse to find the last relevant character
    for (int i = length - 1; i >= 0; i--) {
        // Check if the current character is not a space or a question mark
        if (s[i] != ' ' && s[i] != '?') {
            ch = s[i]; // Store the character
            break; // Exit the loop once the character is found
        }
    }

    // Convert the character to lowercase for uniform comparison
    ch = tolower(ch);

    // Check if the character is a vowel or 'y'
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        printf("YES\n"); // Print "YES" if it is a vowel
    } else {
        printf("NO\n"); // Print "NO" if it is not a vowel
    }

    return 0;
}
