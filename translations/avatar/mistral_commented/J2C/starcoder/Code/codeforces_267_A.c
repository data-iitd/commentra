#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, min, max, result, curr_min, curr_max;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        min = (a < b)? a : b;
        max = (a > b)? a : b;
        result = 0;
        while(min > 0)
        {
            result += max / min;
            max = max % min;
            curr_min = (min < max)? min : max;
            curr_max = (min > max)? min : max;
            min = curr_min;
            max = curr_max;
        }
        printf("%d\n", result);
    }
    return 0;
}

