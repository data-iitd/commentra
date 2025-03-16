
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, i, ar[100], max, min;
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%d", &ar[i]);
    }
    max = 0;
    min = 0;
    for (i = 0; i < a; i++)
    {
        max = max > (ar[i] - ar[0]) ? max : (ar[i] - ar[0]);
        if (i == 0)
        {
            min = ar[i + 1] - ar[i];
        }
        else if (i == a - 1)
        {
            min = ar[i] - ar[i - 1];
        }
        else
        {
            min = min < (ar[i] - ar[i - 1]) ? min : (ar[i] - ar[i - 1]);
            min = min < (ar[i + 1] - ar[i]) ? min : (ar[i + 1] - ar[i]);
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}

