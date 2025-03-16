
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, sub, test, count;
    scanf("%d %d", &n, &m);
    int a[m];
    if (n % m == 0)
    {
        for (int i = 0; i < m; i++)
        {
            a[i] = n / m;
        }
    }
    else
    {
        sub = n / m;
        for (int i = 0; i < m; i++)
        {
            a[i] = sub;
        }
        test = n - (sub * m);
        count = 0;
        for (int i = 0; i < test; i++)
        {
            a[count] = a[count] + 1;
            count++;
            if (count >= m)
                count = 0;
        }
    }
    for (int i = (m - 1); i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

