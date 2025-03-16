#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, res = 0;
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }
    for (i = 1; i < n; i++)
    {
        res += abs(b[i] - b[i - 1]);
    }
    printf("%d", res);
    return 0;
}
