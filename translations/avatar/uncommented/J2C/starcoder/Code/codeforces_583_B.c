#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[100000], b[100000], s, tem, q;
    while(scanf("%d", &n)!= EOF)
    {
        s = -1;
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            b[i] = 0;
        tem = 1;
        q = 0;
        while(q!= n)
        {
            s++;
            if(tem == 1)
            {
                for(int i = 0; i < n; i++)
                    if(a[i] <= q && b[i] == 0)
                    {
                        b[i] = 1;
                        q++;
                    }
                tem = 0;
            }
            else
            {
                for(int i = n - 1; i >= 0; i--)
                    if(a[i] <= q && b[i] == 0)
                    {
                        b[i] = 1;
                        q++;
                    }
                tem = 1;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}
