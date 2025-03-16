#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, x, y, z, i, j, k, cnt;
    scanf("%d", &n);
    scanf("%d", &m);
    int *par = (int *)malloc(sizeof(int) * n);
    int *rank = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        par[i] = i;
        rank[i] = 0;
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &z);
        x--;
        y--;
        if(z == 1)
        {
            if(par[x]!= par[y])
            {
                if(rank[x] < rank[y])
                {
                    par[x] = y;
                }
                else
                {
                    par[y] = x;
                    if(rank[x] == rank[y])
                        rank[x]++;
                }
            }
        }
        else
        {
            if(par[x] == par[y])
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
