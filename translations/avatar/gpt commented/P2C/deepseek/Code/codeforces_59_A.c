#include <stdio.h>
#include <ctype.h>

int main() {
    char txt[1000];  // Buffer to store input text
    int cu = 0;      // Counter for uppercase letters
    int cl = 0;      // Counter for lowercase letters

    // Get input from the user
    fgets(txt, sizeof(txt), stdin);

    // Iterate through each character in the input text
    for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
        // Check if the character is lowercase
        if (islower(txt[i])) {
            cl++;  // Increment lowercase counter
        } else {
            cu++;  // Increment uppercase counter
        }
    }

    // Compare the counts of uppercase and lowercase letters
    if (cu > cl) {
        // If there are more uppercase letters, convert the text to uppercase
        for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
            printf("%c", toupper(txt[i]));
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
            printf("%c", tolower(txt[i]));
        }
    }

    // Print a newline character
    printf("\n");

    return 0;
}
