
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, a[100000], i, j, k, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % (n * (n + 1) / 2))
    {
        printf("NO");
    }
    else
    {
        k = sum / (n * (n + 1) / 2);
        a[n] = a[0];
        for (i = 1; i <= n; i++)
        {
            if (((k - a[i - 1] + a[i]) % n) || ((k - a[i - 1] + a[i]) / n >= 0))
            {
                printf("NO");
                break;
            }
        }
        if (i > n)
        {
            printf("YES");
        }
    }
    return 0;
}

