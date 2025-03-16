#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100], t[100];
    int i, j;

    scanf("%s", s);

    t[0] = s[0];
    t[1] = s[strlen(s) - 1];
    t[2] = '\0';

    printf("%s\n", t);

    return 0;
}

