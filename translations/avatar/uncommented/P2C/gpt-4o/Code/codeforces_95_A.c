#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    scanf("%d", &pya);
    getchar(); // To consume the newline character after the integer input

    char arre[100][100]; // Assuming a maximum of 100 strings of length 100
    for (int i = 0; i < pya; i++) {
        fgets(arre[i], sizeof(arre[i]), stdin);
        // Remove newline character from the end
        arre[i][strcspn(arre[i], "\n")] = 0;
        // Convert to lowercase
        for (int j = 0; arre[i][j]; j++) {
            arre[i][j] = tolower(arre[i][j]);
        }
    }

    char oString[100];
    fgets(oString, sizeof(oString), stdin);
    oString[strcspn(oString, "\n")] = 0; // Remove newline character

    char lowString[100];
    strcpy(lowString, oString);
    for (int j = 0; lowString[j]; j++) {
        lowString[j] = tolower(lowString[j]);
    }

    char letter1 = tolower(getchar());
    char letter2 = (letter1 != 'a') ? 'a' : 'b';

    int valid[100] = {0}; // Assuming the length of oString is at most 100
    int setcito[100] = {0}; // To store indices
    int setcito_count = 0;

    for (int x = 0; x < pya; x++) {
        char *found = strstr(lowString, arre[x]);
        while (found) {
            int index = found - lowString;
            for (int i = index; i < index + strlen(arre[x]); i++) {
                setcito[setcito_count++] = i;
            }
            found = strstr(found + 1, arre[x]);
        }
    }

    for (int i = 0; i < strlen(oString); i++) {
        for (int j = 0; j < setcito_count; j++) {
            if (i == setcito[j]) {
                char letter = (lowString[i] != letter1) ? letter1 : letter2;
                oString[i] = (islower(oString[i])) ? letter : toupper(letter);
            }
        }
    }

    printf("%s\n", oString);
    return 0;
}

// <END-OF-CODE>
