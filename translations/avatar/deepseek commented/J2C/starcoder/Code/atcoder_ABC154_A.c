
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);
    int a, b;
    scanf("%d %d", &a, &b);
    char u[100];
    scanf("%s", u);
    if(strcmp(u, str) == 0)
        printf("%d %d\n", a-1, b);
    else
        printf("%d %d\n", a, b-1);
    return 0;
}

