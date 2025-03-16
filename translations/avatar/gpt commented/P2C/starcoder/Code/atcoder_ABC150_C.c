#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, pn, qn;
    int i, j, k;
    int *orig, *p, *q;

    scanf("%d", &n);
    orig = (int *)malloc(n * sizeof(int));
    p = (int *)malloc(n * sizeof(int));
    q = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &orig[i]);
    }

    scanf("%d", &pn);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    scanf("%d", &qn);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    pn = -1;
    for (i = 0; i < n; i++)
    {
        if (memcmp(orig[i], p, n * sizeof(int)) == 0)
        {
            pn = i;
            break;
        }
    }

    qn = -1;
    for (i = 0; i < n; i++)
    {
        if (memcmp(orig[i], q, n * sizeof(int)) == 0)
        {
            qn = i;
            break;
        }
    }

    printf("%d\n", abs(pn - qn));

    return 0;
}

