
#include <stdio.h>
#include <string.h>

int main()
{
    char soz[100];
    int a[100], i, j, n, m, l;

    scanf("%s", soz);

    for (i = 0; i < strlen(soz); i++)
    {
        a[i] = 0;
    }

    for (i = 1; i < strlen(soz); i++)
    {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i])
        {
            a[i]++;
        }
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &m, &l);
        printf("%d\n", a[l - 1] - a[m - 1]);
    }

    return 0;
}

