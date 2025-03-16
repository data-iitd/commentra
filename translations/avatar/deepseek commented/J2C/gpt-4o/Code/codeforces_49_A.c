#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000]; // Declare a string to hold the input
    fgets(s, sizeof(s), stdin); // Read a line of input from the user

    int length = strlen(s); // Calculate the length of the string s
    char ch = 0; // Initialize a character variable ch to 0

    // Iterate through the string s in reverse order, starting from the last character
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') { // Check if the current character is not a space or a question mark
            ch = s[i]; // Assign the current character to the variable ch
            break; // Exit the loop
        }
    }

    ch = tolower(ch); // Convert the character ch to lowercase

    // Check if ch is one of the vowels (a, e, i, o, u, y)
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        printf("YES\n"); // Print "YES" if ch is a vowel
    } else {
        printf("NO\n"); // Print "NO" if ch is not a vowel
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
