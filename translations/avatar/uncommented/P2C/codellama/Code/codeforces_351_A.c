
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, i, j, o, arr_sum, res;
    double arr[100000], temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
    }

    for (i = 0, j = 0; i < n; i++)
    {
        if (arr[i] - (int)arr[i] != 0)
        {
            temp = arr[i] - (int)arr[i];
            arr[j] = temp;
            j++;
        }
    }

    o = 2 * n - j;
    arr_sum = 0;
    for (i = 0; i < j; i++)
    {
        arr_sum += arr[i];
    }

    res = 2e9;
    for (i = 0; i < n + 1; i++)
    {
        if (i + o >= n)
        {
            res = min(res, abs(i - arr_sum));
        }
    }

    printf("%.3f", res);

    return 0;
}

