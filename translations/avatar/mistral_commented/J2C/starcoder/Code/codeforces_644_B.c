#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, b, t, d;
    scanf("%d %d", &n, &b);
    long ans[n];
    int i;
    long min;
    long *q = (long *)malloc(sizeof(long) * b);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &t, &d);
        min = 0;
        while(q[min] <= t)
        {
            min++;
        }
        if(min <= b)
        {
            if(min == 0)
            {
                ans[i] = t + d;
            }
            else
            {
                ans[i] = q[min - 1] + d;
            }
            q[min] = ans[i];
        }
        else
        {
            ans[i] = -1;
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%ld ", ans[i]);
    }
    return 0;
}

