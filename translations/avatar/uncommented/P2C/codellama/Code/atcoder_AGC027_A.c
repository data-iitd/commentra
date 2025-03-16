
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, x, i, ans = 0;
    scanf("%d", &n);
    scanf("%d", &x);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    if (a[0] > x)
    {
        printf("0");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }
    if (x != 0)
    {
        ans--;
    }
    printf("%d", ans);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

