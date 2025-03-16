
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, sub, test, count;
    int *a;

    scanf("%d %d", &n, &m);

    a = (int *)malloc(m * sizeof(int));

    if (n % m == 0)
    {
        for (i = 0; i < m; i++)
        {
            a[i] = n / m;
        }
    }
    else
    {
        sub = n / m;
        for (i = 0; i < m; i++)
        {
            a[i] = sub;
        }
        test = n - (sub * m);
        count = 0;
        for (i = 0; i < test; i++)
        {
            a[count] = a[count] + 1;
            count++;
            if (count > m)
                count = 0;
        }
    }

    for (i = m - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}

