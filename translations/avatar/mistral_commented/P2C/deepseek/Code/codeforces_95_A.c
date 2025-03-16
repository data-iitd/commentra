#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    scanf("%d", &pya);
    char *arre[pya];

    for (int i = 0; i < pya; i++) {
        char x[100];
        scanf("%s", x);
        int len = strlen(x);
        arre[i] = (char *)malloc((len + 1) * sizeof(char));
        for (int j = 0; j < len; j++) {
            arre[i][j] = tolower(x[j]);
        }
        arre[i][len] = '\0';
    }

    char oString[1000];
    scanf("%s", oString);
    char letter1[2];
    scanf("%s", letter1);
    letter1[0] = tolower(letter1[0]);
    char letter2 = (letter1[0] == 'a') ? 'b' : 'a';

    int valid[1000] = {0};
    int setcito[1000] = {0};
    int setcitoSize = 0;

    for (int i = 0; i < pya; i++) {
        char *x = arre[i];
        char *pos = strstr(oString, x);
        while (pos != NULL) {
            int index = pos - oString;
            valid[index] = 1;
            setcito[setcitoSize++] = index;
            pos = strstr(pos + 1, x);
        }
    }

    for (int i = 0; i < setcitoSize; i++) {
        int index = setcito[i];
        char letter = (islower(oString[index]) != islower(letter1[0])) ? letter1[0] : letter2;
        oString[index] = islower(oString[index]) ? letter : toupper(letter);
    }

    for (int i = 0; i < strlen(oString); i++) {
        printf("%c", oString[i]);
    }
    printf("\n");

    for (int i = 0; i < pya; i++) {
        free(arre[i]);
    }

    return 0;
}
