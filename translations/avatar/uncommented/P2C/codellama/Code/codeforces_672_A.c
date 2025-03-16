
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int count = 0;
    int *li = (int *)malloc(371 * sizeof(int));
    for (i = 1; i <= 371; i++)
    {
        p = i;
        q = i;
        while (p != 0)
        {
            p /= 10;
            count++;
        }
        if (count == 1)
        {
            li[i - 1] = i;
        }
        if (count == 2)
        {
            while (q != 0)
            {
                x = q % 10;
                q /= 10;
                li[i - 1] = x;
            }
        }
        if (count == 3)
        {
            while (q != 0)
            {
                x = q % 10;
                q /= 10;
                li[i - 1] = x;
            }
        }
    }
    li[370] = 0;
    li[369] = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("%d", li[n - 1]);
    return 0;
}

