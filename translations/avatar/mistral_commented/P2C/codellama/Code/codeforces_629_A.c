
#include <stdio.h>

int main()
{
    int n, i, j, chocCount, nfat, happiness, posCount;
    char line[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", line);

        chocCount = 0;
        nfat = 1;

        for (j = 0; j < strlen(line); j++)
        {
            if (line[j] == 'C')
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
    }

    for (j = 0; j < n; j++)
    {
        chocCount = 0;

        for (i = 0; i < n; i++)
        {
            if (line[i][j] == 'C')
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
    }

    printf("%d", happiness);

    return 0;
}

