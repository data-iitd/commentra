#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    scanf("%d", &pya);
    char *arre[pya];
    for (int i = 0; i < pya; i++) {
        arre[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arre[i]);
        for (int j = 0; arre[i][j]; j++) {
            arre[i][j] = tolower(arre[i][j]);
        }
    }

    char oString[1000];
    scanf("%s", oString);
    for (int i = 0; oString[i]; i++) {
        oString[i] = tolower(oString[i]);
    }

    char letter1;
    scanf(" %c", &letter1);
    char letter2 = (letter1 == 'a') ? 'b' : 'a';

    int valid[1000] = {0};
    int setcito[1000] = {0};
    int setcitoSize = 0;

    for (int i = 0; i < pya; i++) {
        char *x = arre[i];
        int len = strlen(x);
        int wat = 0;
        while ((wat = oString.find(x, wat)) != string::npos) {
            for (int j = wat; j < wat + len; j++) {
                int found = 0;
                for (int k = 0; k < setcitoSize; k++) {
                    if (setcito[k] == j) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    setcito[setcitoSize++] = j;
                }
            }
            wat++;
        }
    }

    for (int i = 0; i < setcitoSize; i++) {
        int index = setcito[i];
        char letter = (lowString[index] == letter1) ? letter2 : letter1;
        if (islower(oString[index])) {
            oString[index] = letter;
        } else {
            oString[index] = toupper(letter);
        }
    }

    for (int i = 0; oString[i]; i++) {
        printf("%c", oString[i]);
    }
    printf("\n");

    for (int i = 0; i < pya; i++) {
        free(arre[i]);
    }

    return 0;
}
