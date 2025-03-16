#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000], t[1000];
    scanf("%s", s);
    t[0] = s[0];
    sprintf(t + 1, "%d", strlen(s) - 2);
    t[strlen(s) - 1] = s[strlen(s) - 1];
    printf("%s\n", t);
    return 0;
}

