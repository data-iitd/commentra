#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    scanf("%d", &pya);
    char arre[pya][100];
    char oString[100];
    char letter1;
    char letter2;
    int valid[100] = {0};
    int setcito[100] = {0};
    int setcito_index = 0;

    // Read pya number of inputs and convert them to lowercase
    for (int i = 0; i < pya; i++) {
        scanf("%s", arre[i]);
        for (int j = 0; j < strlen(arre[i]); j++) {
            arre[i][j] = tolower(arre[i][j]);
        }
    }

    // Read the original string
    scanf("%s", oString);
    for (int i = 0; i < strlen(oString); i++) {
        oString[i] = tolower(oString[i]);
    }

    // Read the first letter and determine the second letter
    scanf(" %c", &letter1);
    letter2 = (letter1 == 'a') ? 'b' : 'a';

    // Iterate over each string in arre and check if it exists in oString
    for (int i = 0; i < pya; i++) {
        char *ptr = strstr(oString, arre[i]);
        while (ptr != NULL) {
            for (int j = 0; j < strlen(arre[i]); j++) {
                valid[ptr - oString + j] = 1;
            }
            ptr = strstr(ptr + 1, arre[i]);
        }
    }

    // Update the characters in oString based on the valid indices and letter rules
    for (int i = 0; i < strlen(oString); i++) {
        if (valid[i]) {
            char letter = (oString[i] == letter1) ? letter2 : letter1;
            oString[i] = (islower(oString[i])) ? letter : toupper(letter);
        }
    }

    // Print the modified oString
    printf("%s\n", oString);

    return 0;
}
