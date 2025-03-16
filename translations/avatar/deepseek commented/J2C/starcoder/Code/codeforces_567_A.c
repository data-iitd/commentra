#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max, min;
    scanf("%d", &n);
    int ar[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    max = ar[1] - ar[0];
    min = ar[n - 1] - ar[n - 2];
    for (i = 1; i < n - 1; i++)
    {
        max = max > (ar[i + 1] - ar[i])? max : (ar[i + 1] - ar[i]);
        min = min < (ar[i] - ar[i - 1])? min : (ar[i] - ar[i - 1]);
    }
    printf("%d %d", min, max);
    return 0;
}
