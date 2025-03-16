#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, count = 0;
    scanf("%d %d", &n, &m);
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%s", a);
        for (j = 0; j < m; j++)
        {
            if (a[j] == 'S')
            {
                k = j;
                break;
            }
        }
        for (l = 0; l < m; l++)
        {
            if (a[l] == 'G')
            {
                count += k - l;
                break;
            }
        }
    }
    printf("%d", count);
    return 0;
}

