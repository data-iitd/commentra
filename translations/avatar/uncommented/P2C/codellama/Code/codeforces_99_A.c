
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char l[100];
    char s[100];
    char p[100];
    int i;
    scanf("%s", l);
    char *token = strtok(l, ".");
    strcpy(s, token);
    token = strtok(NULL, ".");
    strcpy(p, token);
    i = atoi(p);
    if (s[strlen(s) - 1] == '9')
    {
        printf("GOTO Vasilisa.\n");
    }
    else if (s[strlen(s) - 1] != '9' && i < 5)
    {
        printf("%s\n", s);
    }
    else
    {
        printf("%d\n", atoi(s) + 1);
    }
    return 0;
}

