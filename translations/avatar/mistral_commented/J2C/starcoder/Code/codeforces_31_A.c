
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, f, t;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(k=0; k<n; k++)
    {
        f = 0;
        t = a[k];
        for(i=0; i<n; i++)
        {
            if(i!=k)
            {
                for(j=0; j<n-1; j++)
                {
                    if(i!=j && t==(a[i]+a[j]))
                    {
                        f = 1;
                        break;
                    }
                }
                if(f==1)
                    break;
            }
        }
        if(f==1)
        {
            printf("%d %d %d\n", k+1, j+1, i+1);
            f = 0;
        }
    }
    if(f==0)
        printf("-1\n");
    return 0;
}

