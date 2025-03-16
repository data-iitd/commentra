
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, m, i, x, val, val2, ans;
    scanf("%d %d", &n, &m);
    int *q1 = (int *)malloc(n * sizeof(int));
    int *q2 = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        scanf("%d", &q1[i]);
        q2[i] = i + 1;
    }
    ans = 0;
    while(n > 0)
    {
        if(q1[0] <= m)
        {
            ans = q2[0];
            q1[0] = q1[n - 1];
            q2[0] = q2[n - 1];
            n--;
        }
        else if(q1[0] > m)
        {
            x = q1[0];
            val = x - m;
            q1[0] = val;
            val2 = q2[0];
            q2[0] = val2;
        }
    }
    printf("%d", ans);
    return 0;
}

