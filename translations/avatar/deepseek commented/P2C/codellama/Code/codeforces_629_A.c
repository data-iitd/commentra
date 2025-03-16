
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, chocCount, nfat, happiness, posCount;
    char line[100];
    char cake[100][100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", line);
        strcpy(cake[i], line);
        for (j = 0; j < strlen(line); j++)
        {
            if (line[j] == 'C')
            {
                chocCount++;
            }
        }
        if (chocCount > 1)
        {
            for (i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

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
            for (i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    printf("%d", happiness);

    return 0;
}

