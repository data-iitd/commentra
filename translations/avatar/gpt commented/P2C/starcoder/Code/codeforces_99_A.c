#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    char p[1000];
    int i;

    scanf("%s.%s", s, p);
    i = p[0] - '0';

    if (s[strlen(s) - 1] == '9')
    {
        printf("GOTO Vasilisa.\n");
    }
    else if (s[strlen(s) - 1]!= '9' && i < 5)
    {
        printf("%s\n", s);
    }
    else
    {
        s[strlen(s)] = '\0';
        i = atoi(s) + 1;
        printf("%d\n", i);
    }

    return 0;
}
