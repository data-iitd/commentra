
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, hole, i, check;
    scanf("%d %d", &a, &b);
    hole = 1;
    i = 0;
    check = 1;
    while (check)
    {
        if (hole >= b)
        {
            check = 0;
        }
        else
        {
            hole = a * (i + 1) - i;
            i++;
        }
    }
    printf("%d", i);
    return 0;
}

