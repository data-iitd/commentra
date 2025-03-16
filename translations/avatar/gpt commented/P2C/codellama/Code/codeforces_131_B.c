#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, c = 0;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == 0)
                c++;
        }
    }
    printf("%d", c);
    return 0;
}
