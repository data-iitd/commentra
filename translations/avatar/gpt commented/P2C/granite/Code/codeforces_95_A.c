
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    char arre[1000][1000];
    char oString[1000];
    char letter1[1000];
    char letter2[1000];
    int valid[1000];
    int setcito[1000];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    // Read an integer input which represents the number of strings to be added to the list
    scanf("%d", &pya);

    // Initialize an empty list to store the input strings
    for (i = 0; i < pya; i++) {
        scanf("%s", arre[i]);
    }

    // Read the original string from user input
    scanf("%s", oString);

    // Convert the original string to lowercase for comparison
    for (i = 0; i < strlen(oString); i++) {
        oString[i] = tolower(oString[i]);
    }

    // Read a letter from user input and convert it to lowercase
    scanf("%s", letter1);
    letter1[0] = tolower(letter1[0]);

    // Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
    letter2[0] = (letter1[0] == 'a')? 'b' : 'a';

    // Initialize a list to track valid indices for replacement
    for (i = 0; i < strlen(oString); i++) {
        valid[i] = 0;
    }

    // Create a set to store unique indices where replacements will occur
    for (i = 0; i < strlen(oString); i++) {
        setcito[i] = 0;
    }

    // Loop through each string in the list 'arre'
    for (i = 0; i < pya; i++) {
        for (j = 0; j < strlen(arre[i]); j++) {
            arre[i][j] = tolower(arre[i][j]);
        }

        for (j = 0; j < strlen(oString); j++) {
            if (strstr(oString + j, arre[i])!= NULL) {
                for (k = 0; k < strlen(arre[i]); k++) {
                    setcito[j + k] = 1;
                }
            }
        }
    }

    // Convert the original string to a list for mutable operations
    for (i = 0; i < strlen(oString); i++) {
        oString[i] = tolower(oString[i]);
    }

    // Loop through the indices stored in'setcito' for replacement
    for (i = 0; i < strlen(oString); i++) {
        if (setcito[i] == 1) {
            if (oString[i] == letter1[0]) {
                oString[i] = letter2[0];
            } else {
                oString[i] = letter1[0];
            }
        }
    }

    // Print the modified string without spaces between characters
    for (i = 0; i < strlen(oString); i++) {
        if (islower(oString[i])) {
            printf("%c", oString[i]);
        } else {
            printf("%c", toupper(oString[i]));
        }
    }

    // Print a newline at the end
    printf("\n");

    return 0;
}

