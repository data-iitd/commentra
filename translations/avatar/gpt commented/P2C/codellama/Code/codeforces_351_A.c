#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    float arr[100000];
    int i, j, k, o;
    float arr_sum = 0;
    float res = 2e9;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] - (int)arr[i] != 0)
        {
            arr_sum += arr[i] - (int)arr[i];
        }
    }

    o = 2 * n - i;

    for (i = 0; i <= n; i++)
    {
        if (i + o >= n)
        {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    printf("%.3f", res);

    return 0;
}

