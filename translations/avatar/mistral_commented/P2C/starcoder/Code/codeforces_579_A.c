#include <stdio.h>
#include <math.h>

int main()
{
    int n, x;

    scanf("%d", &n);

    x = 1;

    while (1)
    {
        if (log2(n) == (int)log2(n))
        {
            break;
        }

        x++;

        n -= pow(2, (int)log2(n));
    }

    printf("%d", x);

    return 0;
}

