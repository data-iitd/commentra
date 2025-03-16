
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, a[1000], i, j, k, sum = 0;
    char str[1000];

    scanf("%d", &n);
    scanf("%s", str);

    for (i = 0; i < n; i++)
    {
        a[i] = str[i] - '0';
        sum += a[i];
    }

    if (sum % (n * (n + 1) / 2))
    {
        printf("NO");
        return 0;
    }

    k = sum / (n * (n + 1) / 2);

    for (i = 0; i < n; i++)
    {
        a[i] = (k - i + a[i]) % n;
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}

