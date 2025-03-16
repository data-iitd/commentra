#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Initialize variables
    int pya;
    scanf("%d", &pya); // Get the number of strings to be processed
    char arre[100][100]; // Initialize an array to store the strings (assuming max 100 strings of max 100 chars)
    
    // Process strings input
    for (int i = 0; i < pya; i++) {
        scanf("%s", arre[i]); // Get the next string
        for (int j = 0; arre[i][j]; j++) {
            arre[i][j] = tolower(arre[i][j]); // Convert to lowercase
        }
    }

    // Get the original string and its first letter
    char oString[100];
    scanf("%s", oString); // Get the original string
    char letter1 = tolower(getchar()); // Get the first letter of the original string in lowercase
    letter1 = tolower(oString[0]); // Correctly get the first letter from the original string

    // Determine the second letter based on the first letter
    char letter2 = (letter1 != 'a') ? 'a' : 'b'; // If the first letter is not 'a', set the second letter to 'b'

    // Initialize a list of valid indices and a set to store the indices of the strings in the original string
    int valid[100] = {0}; // Initialize a list of zeros with the length of the original string
    int setcito[100] = {0}; // Initialize an array to store indices
    int setSize = 0; // Size of the set

    // Find the indices of the strings in the original string
    for (int k = 0; k < pya; k++) {
        char *found = strstr(oString, arre[k]); // Check if the original string contains the current string
        if (found) {
            int index = found - oString; // Get the index of the found string
            for (int i = index; i < index + strlen(arre[k]); i++) {
                setcito[setSize++] = i; // Add the index to the set
            }
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (int i = 0; i < strlen(oString); i++) {
        for (int j = 0; j < setSize; j++) {
            if (i == setcito[j]) {
                char letter = (islower(oString[i]) != islower(letter1)) ? letter1 : letter2; // Determine the letter to replace
                oString[i] = islower(oString[i]) ? letter : toupper(letter); // Replace the letter with the determined letter, preserving the case
            }
        }
    }

    // Print the modified string
    printf("%s\n", oString); // Print the modified string

    return 0;
}

// <END-OF-CODE>
