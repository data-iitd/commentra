#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char soz[100000];
    int a[100000];
    int n, m, l;
    scanf("%s", soz);
    scanf("%d", &n);
    for (int i = 1; i < strlen(soz); i++)
    {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i])
            a[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &m, &l);
        printf("%d\n", a[l - 1] - a[m - 1]);
    }
    return 0;
}
