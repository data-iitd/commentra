
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, b, ac, bc;
    scanf("%d", &n);
    int l1[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l1[i]);
    }
    qsort(l1, n, sizeof(int), compare);
    a = l1[n - 1];
    b = l1[0];
    ac = 0;
    bc = 0;
    for (i = 0; i < n; i++)
    {
        if (l1[i] == a)
        {
            ac++;
        }
        if (l1[i] == b)
        {
            bc++;
        }
    }
    if (a == b)
    {
        printf("%d %d\n", a - b, (n * (n - 1)) / 2);
    }
    else
    {
        printf("%d %d\n", a - b, ac * bc);
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

