#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1000];
    char ch;
    int length = 0;

    // Read a line of input from the user and store it in the array s
    fgets(s, sizeof(s), stdin);

    // Calculate the length of the string s
    while (s[length] != '\0' && s[length] != '\n') {
        length++;
    }

    // Iterate through the string s in reverse order, starting from the last character
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') { // Check if the current character is not a space or a question mark
            ch = s[i]; // Assign the current character to the variable ch
            break; // Exit the loop
        }
    }

    // Convert the character ch to lowercase
    ch = tolower(ch);

    // Check if ch is one of the vowels (a, e, i, o, u, y)
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        printf("YES\n"); // Print "YES" if ch is a vowel
    } else {
        printf("NO\n"); // Print "NO" if ch is not a vowel
    }

    return 0;
}
