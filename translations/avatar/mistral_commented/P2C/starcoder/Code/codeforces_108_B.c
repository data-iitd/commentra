
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1] * 2 && a[i]!= a[i - 1])
        {
            printf("YES\n");
            break;
        }
    }
    if (i == n)
    {
        printf("NO\n");
    }
    return 0;
}

