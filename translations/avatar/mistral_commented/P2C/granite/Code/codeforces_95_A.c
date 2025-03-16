
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya; // Number of strings to be processed
    char arre[1000][100]; // Array to store the strings
    char oString[1000]; // Original string
    char letter1; // First letter of the original string
    char letter2; // Second letter to replace
    int valid[1000]; // Array to store valid indices
    int setcito[1000]; // Array to store indices of the strings in the original string
    int i, j, k, l;

    // Process strings input
    scanf("%d", &pya); // Get the number of strings to be processed
    for (i = 0; i < pya; i++) {
        scanf("%s", arre[i]); // Get the next string
    }

    // Get the original string and its first letter
    scanf("%s", oString); // Get the original string
    letter1 = tolower(oString[0]); // Get the first letter of the original string in lowercase
    letter2 = (letter1 == 'a')? 'b' : 'a'; // Determine the second letter based on the first letter

    // Initialize valid indices and indices of the strings in the original string
    for (i = 0; i < strlen(oString); i++) {
        valid[i] = 0; // Set all indices to 0
    }
    for (i = 0; i < pya; i++) {
        for (j = 0; j < strlen(oString); j++) {
            for (k = 0; k < strlen(arre[i]); k++) {
                if (tolower(oString[j + k])!= tolower(arre[i][k])) {
                    break; // If the characters do not match, break the loop
                }
            }
            if (k == strlen(arre[i])) { // If all characters match
                for (l = j; l < j + strlen(arre[i]); l++) {
                    valid[l] = 1; // Set the valid indices to 1
                }
            }
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (i = 0; i < strlen(oString); i++) {
        if (valid[i] == 1) { // If the index is valid
            if (islower(oString[i])) { // If the letter is lowercase
                oString[i] = (oString[i] == letter1)? letter2 : letter1; // Replace the letter with the determined letter
            } else { // If the letter is uppercase
                oString[i] = (oString[i] == toupper(letter1))? toupper(letter2) : toupper(letter1); // Replace the letter with the determined letter
            }
        }
    }

    // Print the modified string
    printf("%s\n", oString); // Print the modified string

    return 0;
}
