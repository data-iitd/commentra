#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int k = i - j;
            if (k < 0)
                k += n;
            int m = a[i];
            for (int l = 0; l < j; l++)
                m = min(m, a[k]);
            b[j][i] = m;
        }
    int m = 1000000000;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
            s += b[j][i];
        m = min(m, s + x * i);
    }
    printf("%d\n", m);
    return 0;
}

