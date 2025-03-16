
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long x, r, newNumber, pow;
    scanf("%ld", &x);
    long list[100000];
    int i = 0;
    while (x > 0)
    {
        r = x % 10;
        if (9 - r < r)
        {
            if (x / 10 == 0 && 9 - r == 0)
            {
                list[i] = r;
            }
            else
            {
                list[i] = 9 - r;
            }
        }
        else
        {
            list[i] = r;
        }
        x = x / 10;
        i++;
    }
    pow = 0;
    newNumber = 0;
    for (i = 0; i < i; i++)
    {
        newNumber = newNumber + list[i] * (long)pow(10, pow);
        pow++;
    }
    printf("%ld", newNumber);
    return 0;
}

