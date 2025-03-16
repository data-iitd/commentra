
#include <stdio.h>
#include <string.h>

int main() {
    char l[100];
    char s[100];
    char p[100];
    int i;

    scanf("%s", l);
    sscanf(l, "%[^.].%s", s, p);
    i = atoi(p);

    if (s[strlen(s) - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    } else if (s[strlen(s) - 1]!= '9' && i < 5) {
        printf("%s\n", s);
    } else {
        s[strlen(s) - 1]++;
        printf("%s\n", s);
    }

    return 0;
}

