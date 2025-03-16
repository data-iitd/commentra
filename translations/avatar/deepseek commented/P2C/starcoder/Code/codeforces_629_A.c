
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, chocCount, nfat, posCount;
    float happiness;
    char cake[100][100];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", cake[i]);
    }

    happiness = 0;
    nfat = 1;
    chocCount = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        if (chocCount > 1)
        {
            for (j = chocCount; j > chocCount - 2; j--)
            {
                nfat *= j;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    posCount = 0;

    for (j = 0; j < n; j++)
    {
        chocCount = 0;
        for (i = 0; i < n; i++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        if (chocCount > 1)
        {
            for (j = chocCount; j > chocCount - 2; j--)
            {
                nfat *= j;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    printf("%d", (int)happiness);

    return 0;
}

