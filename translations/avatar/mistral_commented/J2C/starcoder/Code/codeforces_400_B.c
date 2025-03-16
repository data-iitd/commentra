
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, count = 0, returnDex = -1;
    char **arrs;
    int *length;

    scanf("%d %d", &n, &m);
    arrs = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
    {
        arrs[i] = (char*)malloc(m * sizeof(char));
        scanf("%s", arrs[i]);
    }

    length = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arrs[i][j] == 'G')
            {
                k = j;
                break;
            }
        }
        for(j = 0; j < m; j++)
        {
            if(arrs[i][j] == 'S')
            {
                l = j;
                break;
            }
        }
        length[i] = l - k;
    }

    for(i = 0; i < n; i++)
    {
        if(length[i] > 0)
        {
            count++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(length[i] > 0)
        {
            if(returnDex == -1)
            {
                returnDex = i;
            }
            else
            {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

