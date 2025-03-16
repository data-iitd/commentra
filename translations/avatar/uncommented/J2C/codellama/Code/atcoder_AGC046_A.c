
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int x;
    int count = 0;
    int tmp;
    x = 0;
    scanf("%d", &x);
    tmp = x;
    while (x != 360)
    {
        x = x + tmp;
        if (x > 360)
        {
            x = x - 360;
        }
        count++;
    }
    printf("%d", count);
    return 0;
}

