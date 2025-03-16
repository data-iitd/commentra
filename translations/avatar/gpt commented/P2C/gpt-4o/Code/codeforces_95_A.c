#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Read an integer input which represents the number of strings to be added to the list
    int pya;
    scanf("%d", &pya);
    getchar(); // Consume the newline character after the integer input

    // Initialize an array of strings to store the input strings
    char arre[100][100]; // Assuming a maximum of 100 strings, each up to 99 characters
    for (int i = 0; i < pya; i++) {
        fgets(arre[i], sizeof(arre[i]), stdin);
        // Convert to lowercase
        for (int j = 0; arre[i][j]; j++) {
            arre[i][j] = tolower(arre[i][j]);
        }
        // Remove newline character if present
        arre[i][strcspn(arre[i], "\n")] = 0;
    }

    // Read the original string from user input
    char oString[100];
    fgets(oString, sizeof(oString), stdin);
    // Convert the original string to lowercase for comparison
    char lowString[100];
    for (int j = 0; oString[j]; j++) {
        lowString[j] = tolower(oString[j]);
    }
    lowString[strcspn(lowString, "\n")] = 0; // Remove newline character

    // Read a letter from user input and convert it to lowercase
    char letter1;
    scanf(" %c", &letter1);
    letter1 = tolower(letter1);

    // Determine the second letter based on the first letter
    char letter2 = (letter1 != 'a') ? 'a' : 'b';

    // Initialize a boolean array to track valid indices for replacement
    int valid[100] = {0};
    // Create a set to store unique indices where replacements will occur
    int setcito[100] = {0}; // Assuming a maximum of 100 unique indices
    int setCount = 0;

    // Loop through each string in the list 'arre'
    for (int x = 0; x < pya; x++) {
        char *found = lowString;
        while ((found = strstr(found, arre[x])) != NULL) {
            // Add the indices of the found string to the set for replacement
            for (int i = 0; i < strlen(arre[x]); i++) {
                int index = found - lowString + i;
                // Check if the index is already in the set
                int alreadyExists = 0;
                for (int k = 0; k < setCount; k++) {
                    if (setcito[k] == index) {
                        alreadyExists = 1;
                        break;
                    }
                }
                if (!alreadyExists) {
                    setcito[setCount++] = index;
                }
            }
            found++; // Move the search position forward
        }
    }

    // Loop through the indices stored in 'setcito' for replacement
    for (int i = 0; i < setCount; i++) {
        int index = setcito[i];
        char letter = (lowString[index] != letter1) ? letter1 : letter2;
        oString[index] = (isupper(oString[index])) ? toupper(letter) : letter;
    }

    // Print the modified string without spaces between characters
    printf("%s", oString);

    // Print a newline at the end
    printf("\n");

    return 0;
}

// <END-OF-CODE>
