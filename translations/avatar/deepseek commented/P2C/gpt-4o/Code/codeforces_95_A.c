#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUTS 100
#define MAX_STRING_LENGTH 1000

int main() {
    int pya;
    scanf("%d", &pya);  // Read the number of inputs to be taken
    char arre[MAX_INPUTS][MAX_STRING_LENGTH];  // Array to store the inputs

    // Read pya number of inputs and convert them to lowercase, then store in arre
    for (int i = 0; i < pya; i++) {
        scanf("%s", arre[i]);
        for (int j = 0; arre[i][j]; j++) {
            arre[i][j] = tolower(arre[i][j]);  // Convert to lowercase
        }
    }

    char oString[MAX_STRING_LENGTH];
    scanf(" %[^\n]", oString);  // Read the original string
    char lowString[MAX_STRING_LENGTH];
    strcpy(lowString, oString);
    for (int i = 0; lowString[i]; i++) {
        lowString[i] = tolower(lowString[i]);  // Convert to lowercase
    }

    char letter1;
    scanf(" %c", &letter1);
    letter1 = tolower(letter1);
    char letter2 = (letter1 != 'a') ? 'a' : 'b';

    int valid[MAX_STRING_LENGTH] = {0};  // Initialize an array of zeros
    int setcito[MAX_STRING_LENGTH] = {0};  // Array to store indices
    int setcito_count = 0;  // Count of valid indices

    // Iterate over each string in arre and check if it exists in lowString
    for (int x = 0; x < pya; x++) {
        char *found = lowString;
        while ((found = strstr(found, arre[x])) != NULL) {  // Find the substring
            for (int i = 0; i < strlen(arre[x]); i++) {
                setcito[setcito_count++] = (found - lowString) + i;  // Add the indices
            }
            found++;  // Move past the last found substring
        }
    }

    // Update the characters in oString based on the setcito indices and letter rules
    for (int i = 0; i < setcito_count; i++) {
        int index = setcito[i];
        char letter = (lowString[index] != letter1) ? letter1 : letter2;
        oString[index] = (islower(oString[index])) ? letter : toupper(letter);
    }

    // Print the modified oString
    printf("%s\n", oString);

    return 0;
}

// <END-OF-CODE>
