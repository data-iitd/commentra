
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char txt[100];  // Declaring a character array `txt` to store the input text.
    int cu = 0;  // Initializing the counter for uppercase letters to zero.
    int cl = 0;  // Initializing the counter for lowercase letters to zero.

    // Taking input from the user and storing it in the character array `txt`.
    printf("Enter a text: ");
    fgets(txt, sizeof(txt), stdin);

    // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
    for (int i = 0; txt[i]!= '\0'; i++) {
        if (islower(txt[i])) {  // Checking if the current character `txt[i]` is lowercase.
            cl = cl + 1;  // Incrementing the counter for lowercase letters if `txt[i]` is lowercase.
        } else {  // If `txt[i]` is not lowercase, it must be uppercase.
            cu = cu + 1;  // Incrementing the counter for uppercase letters.
        }
    }

    // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
    char out[100];  // Declaring a character array `out` to store the output text.
    if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
        strcpy(out, txt);  // Copying the entire text from `txt` to `out` and converting it to uppercase.
        for (int i = 0; out[i]!= '\0'; i++) {
            out[i] = toupper(out[i]);
        }
    } else {  // If there are more lowercase letters than uppercase letters or equal counts.
        strcpy(out, txt);  // Copying the entire text from `txt` to `out` and converting it to lowercase.
        for (int i = 0; out[i]!= '\0'; i++) {
            out[i] = tolower(out[i]);
        }
    }

    // Printing the result stored in `out`.
    printf("%s\n", out);

    return 0;
}
