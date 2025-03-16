
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, sum;
    scanf("%d %d", &a, &b);
    sum = 0;
    for (int i = 0; i < 2; i++)
    {
        if (a >= b)
        {
            sum += a;
            a--;
        }
        else
        {
            sum += b;
            b--;
        }
    }
    printf("%d\n", sum);
    return 0;
}

