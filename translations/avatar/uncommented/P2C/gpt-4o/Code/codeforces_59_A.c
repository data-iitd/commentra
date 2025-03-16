#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char txt[100]; // Assuming the input will not exceed 99 characters
    int cu = 0, cl = 0;

    // Read input
    fgets(txt, sizeof(txt), stdin);
    
    // Remove newline character if present
    txt[strcspn(txt, "\n")] = 0;

    // Count uppercase and lowercase letters
    for (int i = 0; txt[i] != '\0'; i++) {
        if (islower(txt[i])) {
            cl++;
        } else if (isupper(txt[i])) {
            cu++;
        }
    }

    // Convert to upper or lower case based on counts
    if (cu > cl) {
        for (int i = 0; txt[i] != '\0'; i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        for (int i = 0; txt[i] != '\0'; i++) {
            txt[i] = tolower(txt[i]);
        }
    }

    // Print the result
    printf("%s\n", txt);

    return 0;
}

// <END-OF-CODE>
