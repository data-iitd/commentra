#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, returnDex, index;
    char arrs[100000][100000];
    int length[100000];
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%s", arrs[i]);
    index = 0;
    returnDex = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arrs[i][j] == 'G')
                k = j;
            if(arrs[i][j] == 'S')
                length[index++] = j - k;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(length[i] == 0)
            returnDex = -1;
        else if(length[i] < 0)
            returnDex = 0;
    }
    if(returnDex == -1)
        printf("%d\n", returnDex);
    else
    {
        int set[100000];
        int setIndex = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < setIndex; j++)
            {
                if(length[i] == set[j])
                {
                    returnDex = 0;
                    break;
                }
            }
            if(returnDex == 0)
                break;
            set[setIndex++] = length[i];
        }
        printf("%d\n", setIndex);
    }
    return 0;
}
