#include <stdio.h>
#include <stdlib.h>

int main()
{
    int li[370], i, ind = 0, p, q, count, x;

    for (i = 1; i < 371; i++)
    {
        p = i, q = i;
        count = 0;

        while (p!= 0)
        {
            p /= 10;
            count++;
        }

        if (count == 1)
        {
            li[ind++] = i;
        }
        else if (count == 2)
        {
            while (q!= 0)
            {
                x = q % 10;
                q /= 10;
                li[ind++] = x;
            }
            for (int j = ind - 1; j >= 0; j--)
            {
                printf("%d", li[j]);
            }
            ind = 0;
        }
        else if (count == 3)
        {
            while (q!= 0)
            {
                x = q % 10;
                q /= 10;
                li[ind++] = x;
            }
            for (int j = ind - 1; j >= 0; j--)
            {
                printf("%d", li[j]);
            }
            ind = 0;
        }
    }

    printf("\nEnter a number: ");
    scanf("%d", &n);
    printf("%d", li[n - 1]);

    return 0;
}

