#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya;
    scanf("%d", &pya);

    char **arre = (char **)malloc(pya * sizeof(char *));
    for (int i = 0; i < pya; i++) {
        arre[i] = (char *)malloc(101 * sizeof(char)); // Assuming max string length of 100
    }

    for (int i = 0; i < pya; i++) {
        scanf("%s", arre[i]);
        for (int j = 0; j < strlen(arre[i]); j++) {
            arre[i][j] = tolower(arre[i][j]);
        }
    }

    char oString[101];
    scanf("%s", oString);

    char lowString[101];
    for (int i = 0; i < strlen(oString); i++) {
        lowString[i] = tolower(oString[i]);
    }
    lowString[strlen(oString)] = '\0';

    char letter1;
    scanf(" %c", &letter1);
    char letter2 = (letter1 == 'a') ? 'b' : 'a';

    int valid[101] = {0};
    int setcito[101] = {0};
    int setcito_index = 0;

    for (int i = 0; i < pya; i++) {
        char *x = arre[i];
        char *pos = lowString;
        while ((pos = strstr(pos, x)) != NULL) {
            for (int j = 0; j < strlen(x); j++) {
                setcito[setcito_index++] = pos - lowString + j;
            }
            pos++;
        }
    }

    for (int i = 0; i < strlen(oString); i++) {
        oString[i] = tolower(oString[i]);
    }

    for (int i = 0; i < setcito_index; i++) {
        int index = setcito[i];
        char letter = (letter1 == oString[index]) ? letter2 : letter1;
        oString[index] = (oString[index] == letter1 || oString[index] == letter2) ? letter : toupper(letter);
    }

    for (int i = 0; i < strlen(oString); i++) {
        printf("%c", oString[i]);
    }
    printf("\n");

    for (int i = 0; i < pya; i++) {
        free(arre[i]);
    }
    free(arre);

    return 0;
}
