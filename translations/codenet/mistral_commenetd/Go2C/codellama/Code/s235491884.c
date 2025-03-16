
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int n;

    scanf("%s", s);

    n = strlen(s);

    printf("%d", 700 + n*100);

    return 0;
}

