#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int a[5] = {10, 100, 1000, 10000, 100000};
    int new = 0;

    scanf("%s", n);

    for (int i = 0; i < strlen(n); i++)
    {
        new += n[i] - '0';
    }

    if (new == 10)
    {
        printf("10\n");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (new == a[i])
            {
                printf("%d\n", a[i]);
                break;
            }
        }

        if (new!= 10)
        {
            printf("%d\n", new);
        }
    }

    return 0;
}

