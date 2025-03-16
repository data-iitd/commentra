
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long x;
    scanf("%ld", &x);
    long r;
    long newNumber = 0;
    int pow = 0;
    while (x > 0)
    {
        r = x % 10;
        if (9 - r < r)
        {
            if (x / 10 == 0 && 9 - r == 0)
            {
                newNumber = newNumber + r;
            }
            else
            {
                newNumber = newNumber + (9 - r);
            }
        }
        else
        {
            newNumber = newNumber + r;
        }
        x = x / 10;
        pow++;
    }
    printf("%ld", newNumber);
    return 0;
}

