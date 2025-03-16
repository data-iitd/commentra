#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, hole, i;
    int check = 1;

    scanf("%d %d", &a, &b);

    hole = 1;
    i = 0;

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
