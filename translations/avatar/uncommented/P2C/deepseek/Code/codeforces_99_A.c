#include <stdio.h>
#include <string.h>

int main() {
    char l[100];
    fgets(l, sizeof(l), stdin);
    char *l_copy = strtok(l, ".");
    char s[100], p[100];
    strcpy(s, l_copy);
    char *p_copy = strtok(NULL, ".");
    strcpy(p, p_copy);
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
