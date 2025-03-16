
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char txt[100];
    int cu = 0, cl = 0;
    int i;

    // Get the text input from the user
    scanf("%s", txt);

    // Iterate through each character in the text input
    for (i = 0; txt[i]!= '\0'; i++) {
        // If the character is lowercase, increment the lowercase count
        if (islower(txt[i])) {
            cl++;
        }
        // If the character is uppercase, increment the uppercase count
        else {
            cu++;
        }
    }

    // Determine the output based on the count of uppercase and lowercase characters
    if (cu > cl) {
        // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
        for (i = 0; txt[i]!= '\0'; i++) {
            txt[i] = toupper(txt[i]);
        }
    }
    else {
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        for (i = 0; txt[i]!= '\0'; i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the output
    printf("%s\n", txt);

    return 0;
}
