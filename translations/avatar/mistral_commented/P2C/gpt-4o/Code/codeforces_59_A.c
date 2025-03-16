#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    // Get the text input from the user
    char txt[1000]; // Assuming a maximum length of 999 characters
    fgets(txt, sizeof(txt), stdin);

    // Initialize the count of uppercase and lowercase characters
    int cu = 0;
    int cl = 0;

    // Iterate through each character in the text input
    for (int i = 0; i < strlen(txt); i++) {
        // If the character is lowercase, increment the lowercase count
        if (islower(txt[i])) {
            cl++;
        }
        // If the character is uppercase, increment the uppercase count
        else if (isupper(txt[i])) {
            cu++;
        }
    }

    // Determine the output based on the count of uppercase and lowercase characters
    if (cu > cl) {
        // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
        for (int i = 0; i < strlen(txt); i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        for (int i = 0; i < strlen(txt); i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the output
    printf("%s", txt);

    return 0;
}

// <END-OF-CODE>
