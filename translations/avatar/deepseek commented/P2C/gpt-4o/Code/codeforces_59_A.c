#include <stdio.h>
#include <ctype.h>  // For islower() and toupper()/tolower()

int main() {
    char txt[100];  // Array to store the input text (assuming a maximum length of 99 characters).
    int cu = 0;     // Counter for uppercase letters.
    int cl = 0;     // Counter for lowercase letters.

    // Taking input from the user and storing it in the variable `txt`.
    printf("Enter text: ");
    fgets(txt, sizeof(txt), stdin);  // Using fgets to read a line of text.

    // Looping through each character in the input text `txt` to count uppercase and lowercase letters.
    for (int i = 0; txt[i] != '\0'; i++) {
        if (islower(txt[i])) {  // Checking if the current character is lowercase.
            cl++;  // Incrementing the counter for lowercase letters.
        } else if (isupper(txt[i])) {  // Checking if the current character is uppercase.
            cu++;  // Incrementing the counter for uppercase letters.
        }
    }

    // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
    if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
        for (int i = 0; txt[i] != '\0'; i++) {
            txt[i] = toupper(txt[i]);  // Convert the entire text to uppercase.
        }
    } else {  // If there are more lowercase letters than uppercase letters or equal counts.
        for (int i = 0; txt[i] != '\0'; i++) {
            txt[i] = tolower(txt[i]);  // Convert the entire text to lowercase.
        }
    }

    printf("%s", txt);  // Printing the result stored in `txt`.

    return 0;  // Indicating that the program ended successfully.
}

// <END-OF-CODE>
