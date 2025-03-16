
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int a = 0;
    while (x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2)
    {
        if (a)
        {
            if (y >= 22)
                y -= 22;
            else if (x >= 1 && y >= 12)
                x -= 1, y -= 12;
            else
                x -= 2, y -= 2;
        }
        else
        {
            if (x >= 2 && y >= 2)
                x -= 2, y -= 2;
            else if (x >= 1 && y >= 12)
                x -= 1, y -= 12;
            else
                y -= 22;
        }
        a = 1 - a;
    }
    printf("%s\n", (a? "Ciel" : "Hanako"));
    return 0;
}

