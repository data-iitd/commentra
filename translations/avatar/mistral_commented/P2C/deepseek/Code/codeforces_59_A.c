#include <stdio.h>
#include <ctype.h>

int main() {
    char txt[1000];
    int cu = 0, cl = 0;

    // Get the text input from the user
    fgets(txt, sizeof(txt), stdin);

    // Iterate through each character in the text input
    for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
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
        for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        for (int i = 0; txt[i] != '\0' && txt[i] != '\n'; i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the output
    printf("%s", txt);

    return 0;
}
