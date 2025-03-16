#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, i, j, chocCount, nfat, happiness, posCount;
    char line[100];
    scanf("%d", &n);
    char cake[n][n];
    for (i = 0; i < n; i++)
    {
        scanf("%s", line);
        strcpy(cake[i], line);
    }
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
    for (j = 0; j < n; j++)
    {
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