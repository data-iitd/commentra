#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, a[1000][2];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    qsort(a, n, sizeof(a[0]), cmp);

    for (i = 0; i < n; i++)
        if (a[i][1] > a[i - 1][1])
        {
            printf("Happy Alex\n");
            break;
        }
    else
        printf("Poor Alex\n");

    return 0;
}

int cmp(const void *a, const void *b)
{
    return ((int *)b)[1] - ((int *)a)[1];
}

