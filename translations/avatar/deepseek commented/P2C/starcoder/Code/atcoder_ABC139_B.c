
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, hole, i;
    scanf("%d %d", &a, &b);
    hole = 1;
    i = 0;
    while (1)
    {
        if (hole >= b)
        {
            break;
        }
        hole = a * (i + 1) - i;
        i++;
    }
    printf("%d", i);
    return 0;
}
