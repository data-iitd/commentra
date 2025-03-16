#include <stdio.h>

int main()
{
    int n, a[1000], i, j, k, sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % (n * (n + 1) / 2))
    {
        printf("NO\n");
        return 0;
    }

    k = sum / (n * (n + 1) / 2);

    for (i = 0; i < n; i++)
    {
        a[i + n] = a[i];
    }

    for (i = 1; i < n; i++)
    {
        if ((k - a[i] + a[i - 1]) % n || (k - a[i] + a[i - 1]) / n < 0)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}

