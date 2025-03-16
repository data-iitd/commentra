#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    long x, r, newNumber, pow;
    int i;
    char *p;
    x = atol(argv[1]);
    while (x > 0)
    {
        r = x % 10;
        if (9 - r < r)
        {
            if (x / 10 == 0 && 9 - r == 0)
                printf("%d", r);
            else
                printf("%d", 9 - r);
        }
        else
            printf("%d", r);
        x = x / 10;
    }
    return 0;
}

