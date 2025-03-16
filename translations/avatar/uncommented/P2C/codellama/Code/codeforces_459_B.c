#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, a, b, ac, bc;
    scanf("%d", &n);
    int l1[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l1[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (l1[i] > l1[j])
            {
                a = l1[i];
                l1[i] = l1[j];
                l1[j] = a;
            }
        }
    }
    a = l1[n - 1];
    b = l1[0];
    if (a == b)
    {
        printf("%d %d\n", a - b, (n) * (n - 1) / 2);
    }
    else
    {
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
        printf("%d %d\n", a - b, ac * bc);
    }
    return 0;
}
