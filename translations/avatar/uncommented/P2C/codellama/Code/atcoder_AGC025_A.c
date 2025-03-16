
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int a[5] = {10, 100, 1000, 10000, 100000};
    int new = 0;
    int i;
    scanf("%s", n);
    for (i = 0; i < strlen(n); i++)
    {
        new += n[i] - '0';
    }
    for (i = 0; i < 5; i++)
    {
        if (a[i] == new)
        {
            printf("10\n");
            break;
        }
    }
    if (i == 5)
    {
        printf("%d\n", new);
    }
    return 0;
}

