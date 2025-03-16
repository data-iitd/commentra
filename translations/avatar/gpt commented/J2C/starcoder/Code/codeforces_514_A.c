#include <stdio.h>
#include <stdlib.h>

int main()
{
    long x, r, newNumber, pow;
    int i;
    scanf("%ld", &x);
    while (x > 0)
    {
        r = x % 10;
        if (9 - r < r)
        {
            if (x / 10 == 0 && 9 - r == 0)
                printf("%ld", r);
            else
                printf("%ld", 9 - r);
        }
        else
            printf("%ld", r);
        x = x / 10;
    }
    return 0;
}

