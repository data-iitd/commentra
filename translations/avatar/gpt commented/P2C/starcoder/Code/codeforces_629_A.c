#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, chocCount, nfat, posCount;
    char cake[100][100];
    int happiness = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%s", cake[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        chocCount = 0;
        for (j = 0; j < n; j++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        
        if (chocCount > 1)
        {
            nfat = 1;
            for (j = chocCount; j > 2; j--)
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
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        
        if (chocCount > 1)
        {
            nfat = 1;
            for (i = chocCount; i > 2; i--)
            {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
    }
    
    printf("%d\n", happiness);
    
    return 0;
}

