#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, q, tem, s;
    int *a, *b;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = 0;
    }
    tem = 1;
    q = 0;
    s = -1;
    while (q != n)
    {
        s++;
        if (tem == 1)
        {
            for (i = 0; i < n; i++)
            {
                if (a[i] <= q && b[i] == 0)
                {
                    b[i] = 1;
                    q++;
                }
            }
            tem = 0;
        }
        else
        {
            for (i = n - 1; i >= 0; i--)
            {
                if (a[i] <= q && b[i] == 0)
                {
                    b[i] = 1;
                    q++;
                }
            }
            tem = 1;
        }
    }
    printf("%d\n", s);
    return 0;
}
