#include <stdio.h>
#include <string.h>

int main() {
    // Take input from the user
    char a[100]; // Assuming the input will not exceed 99 characters
    fgets(a, sizeof(a), stdin);

    // Define a string of vowels (both lowercase and uppercase)
    char *vo = "aeiouyAEIOUY";

    // Get the length of the input string
    int len = strlen(a);

    // Iterate through the input string in reverse order
    for (int i = len - 1; i >= 0; i--) {
        // Check if the current character is a space or a question mark
        if (a[i] == ' ' || a[i] == '?') {
            continue; // Skip to the next iteration if it is a space or '?'
        } else {
            // Check if the current character is a vowel
            if (strchr(vo, a[i]) != NULL) {
                printf("YES\n"); // Print "YES" if it is a vowel
            } else {
                printf("NO\n");  // Print "NO" if it is not a vowel
            }
            break; // Exit the loop after processing the first non-space character
        }
    }

    return 0;
}
// <END-OF-CODE>
