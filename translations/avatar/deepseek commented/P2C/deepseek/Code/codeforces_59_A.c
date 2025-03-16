#include <stdio.h>
#include <ctype.h>

int main() {
    char txt[1000];  // Declaring a character array to store the input text with a maximum length of 1000 characters.
    int cu = 0;  // Initializing the counter for uppercase letters to zero.
    int cl = 0;  // Initializing the counter for lowercase letters to zero.

    // Taking input from the user and storing it in the character array `txt`.
    fgets(txt, sizeof(txt), stdin);

    // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
    for (int i = 0; txt[i] != '\0'; i++) {
        if (islower(txt[i])) {  // Checking if the current character `txt[i]` is lowercase.
            cl++;  // Incrementing the counter for lowercase letters if `txt[i]` is lowercase.
        } else if (isupper(txt[i])) {  // Checking if the current character `txt[i]` is uppercase.
            cu++;  // Incrementing the counter for uppercase letters if `txt[i]` is uppercase.
        }
    }

    // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
    if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
        for (int i = 0; txt[i] != '\0'; i++) {
            printf("%c", toupper(txt[i]));  // Convert the entire text to uppercase and print it.
        }
    } else {  // If there are more lowercase letters than uppercase letters or equal counts.
        for (int i = 0; txt[i] != '\0'; i++) {
            printf("%c", tolower(txt[i]));  // Convert the entire text to lowercase and print it.
        }
    }

    printf("\n");  // Printing a newline character.
    return 0;
}
