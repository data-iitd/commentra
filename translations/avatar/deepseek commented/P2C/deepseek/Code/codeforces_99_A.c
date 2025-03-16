#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char l[1000];
    fgets(l, sizeof(l), stdin);
    char *token = strtok(l, ".");
    char s[500], p[500];
    strcpy(s, token);
    token = strtok(NULL, ".");
    strcpy(p, token);
    int i = p[0] - '0';

    if (s[strlen(s) - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    } else if (s[strlen(s) - 1] != '9' && i < 5) {
        printf("%s\n", s);
    } else {
        int num = atoi(s);
        num += 1;
        printf("%d\n", num);
    }

    return 0;
}

