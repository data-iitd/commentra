#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = 0;
    for (int i = 0; i < 2; i++)
    {
        c += (a > b)? a : b;
        if (a > b)
            a--;
        else
            b--;
    }
    printf("%d", c);
    return 0;
}
