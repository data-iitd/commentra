#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, i, j, count_a = 0, count_b = 0;
    scanf("%d", &n);
    int l1[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l1[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (l1[i] == l1[n - 1])
        {
            count_a++;
        }
        if (l1[i] == l1[0])
        {
            count_b++;
        }
    }
    if (count_a == 0 && count_b == 0)
    {
        printf("%d %d", l1[n - 1] - l1[0], n * (n - 1) / 2);
    }
    else
    {
        printf("%d %d", l1[n - 1] - l1[0], count_a * count_b);
    }
    return 0;
}
