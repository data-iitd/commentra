#include <stdio.h>
#include <string.h>

int main() {
    // Define a string containing all the vowels in upper and lower case
    char *vo = "aeiouyAEIOUY";
    
    // Take an input string 'a' from the user
    char a[100]; // Assuming the input will not exceed 99 characters
    fgets(a, sizeof(a), stdin);
    
    // Remove the newline character from the input if present
    a[strcspn(a, "\n")] = 0;

    // Get the length of the string 'a'
    int len = strlen(a);
    
    // Iterate through the string 'a' from the end to the beginning
    for (int i = len - 1; i >= 0; i--) {
        // If the current character is a space or a question mark, skip it
        if (a[i] == ' ' || a[i] == '?') {
            continue;
        } else {
            // Check if the current character is a vowel
            if (strchr(vo, a[i]) != NULL) {
                // If it is, print "YES" and break out of the loop
                printf("YES\n");
                break;
            } else {
                // If it is not, print "NO" and break out of the loop
                printf("NO\n");
                break;
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
