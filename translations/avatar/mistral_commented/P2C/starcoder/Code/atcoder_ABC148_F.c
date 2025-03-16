#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ta, ao;
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; ao--;
    int g[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j] = 0;
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a-1][b-1] = 1;
        g[b-1][a-1] = 1;
    }
    int ta_dist[n], ao_dist[n];
    for(int i=0;i<n;i++)
    {
        ta_dist[i] = ao_dist[i] = 0;
    }
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;
    for(int i=0;i<n;i++)
    {
        if(ta_dist[i] == 0)
        {
            int v = i;
            for(int j=0;j<n;j++)
            {
                if(g[v][j] == 1)
                {
                    ta_dist[j] = 1;
                    v = j;
                }
            }
        }
        if(ao_dist[i] == 0)
        {
            int v = i;
            for(int j=0;j<n;j++)
            {
                if(g[v][j] == 1)
                {
                    ao_dist[j] = 1;
                    v = j;
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(ta_dist[i] == 0 || ao_dist[i] == 0 || ta_dist[i] > ao_dist[i]) continue;
        res = max(res, ao_dist[i]);
    }
    printf("%d", res-1);
    return 0;
}

