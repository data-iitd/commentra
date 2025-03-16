
#include <stdio.h>
#include <ctype.h>

int main() {
    char txt[100];
    int cu = 0, cl = 0;
    int i;

    // Get input from the user
    printf("Enter a text: ");
    fgets(txt, 100, stdin);

    // Iterate through each character in the input text
    for (i = 0; txt[i]!= '\0'; i++) {
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
        for (i = 0; txt[i]!= '\0'; i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (i = 0; txt[i]!= '\0'; i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the resulting output
    printf("Result: %s\n", txt);

    return 0;
}
