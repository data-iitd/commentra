#include <stdio.h>
#include <string.h>

int main() {
    char a[100];  // Declare a character array to hold the input string
    printf("Enter a string: ");
    fgets(a, sizeof(a), stdin);  // Take input from the user

    char vo[] = "aeiouyAEIOUY";  // Define a string of vowels
    int length = strlen(a);  // Get the length of the input string

    // Iterate over the input string in reverse order
    for (int i = length - 1; i >= 0; i--) {
        if (a[i] == ' ' || a[i] == '?') {  // Check if the current character is a space or a question mark
            continue;  // Continue to the next iteration
        } else {
            // Check if the current character is a vowel
            if (strchr(vo, a[i]) != NULL) {  // Use strchr to check for vowels
                printf("YES\n");  // Print "YES" if the character is a vowel
            } else {
                printf("NO\n");  // Print "NO" if the character is not a vowel
            }
            break;  // Break the loop after printing the result
        }
    }

    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
