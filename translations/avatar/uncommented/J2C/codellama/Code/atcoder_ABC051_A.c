
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    scanf("%s", a);
    char *p = strtok(a, ",");
    while (p != NULL)
    {
        printf("%s ", p);
        p = strtok(NULL, ",");
    }
    printf("\n");
    return 0;
}

