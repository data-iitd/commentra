#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char txt[100];  // Array to hold the input text
    int cu = 0;     // Counter for uppercase letters
    int cl = 0;     // Counter for lowercase letters

    // Get input from the user
    printf("Enter text: ");
    fgets(txt, sizeof(txt), stdin);  // Read a line of text

    // Iterate through each character in the input text
    for (int i = 0; i < strlen(txt); i++) {
        // Check if the character is lowercase
        if (islower(txt[i])) {
            cl++;  // Increment lowercase counter
        } else if (isupper(txt[i])) {
            cu++;  // Increment uppercase counter
        }
    }

    // Compare the counts of uppercase and lowercase letters
    if (cu > cl) {
        // If there are more uppercase letters, convert the text to uppercase
        for (int i = 0; i < strlen(txt); i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (int i = 0; i < strlen(txt); i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the resulting output
    printf("%s", txt);

    return 0;
}

// <END-OF-CODE>
