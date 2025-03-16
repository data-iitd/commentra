#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int i, j, k, l, m, new;
    char a[5][6] = {"10", "100", "1000", "10000", "100000"};

    scanf("%s", n);

    for (i = 0; i < 5; i++)
    {
        if (strcmp(n, a[i]) == 0)
        {
            printf("10\n");
            break;
        }
    }

    if (i == 5)
    {
        new = 0;
        for (j = 0; j < strlen(n); j++)
        {
            new += n[j] - '0';
        }
        printf("%d\n", new);
    }

    return 0;
}

