#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, sum, mod;
    scanf("%d", &y);
    sum = 0;
    mod = 0;
    for (int i = y + 1; ; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100!= 0))
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
        if (sum % 7 == 0)
        {
            if ((i % 400 == 0 && y % 400 == 0) || (i % 4 == 0 && i % 100!= 0 && y % 4 == 0 && y % 100!= 0))
            {
                printf("%d\n", i);
                return 0;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}

