
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, hole, i;
    bool check;

    scanf("%d %d", &a, &b);
    hole = 1;
    i = 0;
    check = true;

    while (check)
    {
        if (hole >= b)
        {
            check = false;
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

