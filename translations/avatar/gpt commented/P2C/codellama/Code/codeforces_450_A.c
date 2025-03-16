#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, mx, ind;
    scanf("%d %d", &n, &m);
    int *l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &l[i]);
    int *l2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        if (l[i] % m == 0)
            l2[i] = l[i] / m;
        else
            l2[i] = l[i] / m + 1;
    }
    mx = l2[0];
    ind = 0;
    for (i = 1; i < n; i++)
    {
        if (l2[i] > mx)
        {
            mx = l2[i];
            ind = i;
        }
    }
    printf("%d\n", ind + 1);
    free(l);
    free(l2);
    return 0;
}
