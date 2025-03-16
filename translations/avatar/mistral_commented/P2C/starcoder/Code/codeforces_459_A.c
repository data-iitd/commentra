#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2, d, x3, y3, x4, y4;
    float numerator, denominator, quotient;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    denominator = x2 - x1;
    numerator = y2 - y1;

    if (denominator == 0)
    {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else if (denominator!= 0)
    {
        quotient = numerator / denominator;
    }

    if (quotient == 1 || quotient == -1)
    {
        if (quotient == 1)
        {
            x4 = x2;
            x3 = x1;
            y3 = y1;
            y4 = y2;
        }
        else
        {
            x4 = x1;
            x3 = x2;
            y3 = y2;
            y4 = y1;
        }
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
