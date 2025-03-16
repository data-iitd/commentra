#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pya; // Initialize variables
    char **arre;
    char oString[1000000];
    char letter1, letter2;
    int valid[1000000];
    int setcito[1000000];
    int i, j, k;

    // Process strings input
    scanf("%d", &pya);
    arre = (char**)malloc(pya * sizeof(char*));
    for (i = 0; i < pya; i++) {
        arre[i] = (char*)malloc(1000000 * sizeof(char));
        scanf("%s", arre[i]);
    }

    // Get the original string and its first letter
    scanf("%s", oString);
    letter1 = getchar();

    // Determine the second letter based on the first letter
    letter2 = 'a' + (letter1 != 'a');

    // Initialize a list of valid indices and a set to store the indices of the strings in the original string
    for (i = 0; i < strlen(oString); i++) {
        valid[i] = 0;
    }
    for (i = 0; i < pya; i++) {
        setcito[i] = 0;
    }

    // Find the indices of the strings in the original string
    for (i = 0; i < pya; i++) {
        for (j = 0; j < strlen(oString); j++) {
            if (strncmp(arre[i], oString + j, strlen(arre[i])) == 0) {
                setcito[i] = j;
                for (k = j; k < j + strlen(arre[i]); k++) {
                    valid[k] = 1;
                }
            }
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (i = 0; i < strlen(oString); i++) {
        if (valid[i]) {
            oString[i] = (oString[i] == tolower(oString[i])) ? letter1 : letter2;
        }
    }

    // Print the modified string
    printf("%s\n", oString);

    // Free memory
    for (i = 0; i < pya; i++) {
        free(arre[i]);
    }
    free(arre);

    return 0;
}

