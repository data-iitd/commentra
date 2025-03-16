
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char soz[100];
    int a[100], i, j, n, m, l;
    scanf("%s", soz);
    for (i = 1; i < strlen(soz); i++)
    {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i])
        {
            a[i] += 1;
        }
    }
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

