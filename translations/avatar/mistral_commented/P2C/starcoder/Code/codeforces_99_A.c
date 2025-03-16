#include <stdio.h>
#include <string.h>

int main()
{
    char l[100];
    scanf("%s", l);
    char *s = strtok(l, ".");
    char *p = strtok(NULL, ".");
    char last_char = s[strlen(s) - 1];
    if (last_char == '9')
    {
        printf("GOTO Vasilisa.\n");
    }
    else if (last_char!= '9' && atoi(p) < 5)
    {
        printf("%s\n", s);
    }
    else
    {
        s[strlen(s) - 1]++;
        printf("%s\n", s);
    }
    return 0;
}

