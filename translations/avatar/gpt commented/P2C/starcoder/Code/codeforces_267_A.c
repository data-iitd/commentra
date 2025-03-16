#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, i, total;
    scanf("%d", &n);
    int *lst = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        total = 0;
        while (a > 0 && b > 0)
        {
            total += a / b;
            a = a % b;
            if (a > 0)
            {
                total += b / a;
                b = b % a;
            }
        }
        if (a == b)
            total = 1;
        lst[i] = total;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", lst[i]);
    return 0;
}

