#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, total;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        total = 0;
        if (a > b)
        {
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
        }
        else if (a < b)
        {
            while (a > 0 && b > 0)
            {
                total += b / a;
                b = b % a;
                if (b > 0)
                {
                    total += a / b;
                    a = a % b;
                }
            }
        }
        else
        {
            total = 1;
        }
        printf("%d\n", total);
    }
    return 0;
}

