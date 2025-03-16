#include <stdio.h>
#include <string.h>

int main() {
    // Define a string containing all the vowels in upper and lower case
    char vo[] = "aeiouyAEIOUY";

    // Take an input string 'a' from the user
    char a[100];
    fgets(a, sizeof(a), stdin);

    // Remove the newline character if present
    a[strcspn(a, "\n")] = 0;

    // Iterate through the string 'a' from the end to the beginning
    for (int i = strlen(a) - 1; i >= 0; i--) {
        // If the current character is a space or a question mark, skip it and move on to the next character
        if (a[i] == ' ' || a[i] == '?') {
            continue;
        }
        // If the current character is not a space or a question mark, check if it is a vowel or not
        else {
            // Check if the current character is a vowel
            if (strchr(vo, a[i])) {
                // If it is, print "YES" and break out of the loop
                printf("YES\n");
                break;
            }
            // If it is not, print "NO" and break out of the loop
            else {
                printf("NO\n");
                break;
            }
        }
    }

    return 0;
}
