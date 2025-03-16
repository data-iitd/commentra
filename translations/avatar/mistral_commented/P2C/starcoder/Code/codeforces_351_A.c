#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    float arr_sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - (int)arr[i]!= 0)
        {
            arr_sum += arr[i];
        }
    }
    float res = 2e9;
    for (int i = 0; i <= n; i++)
    {
        if (i + 2 * n - i >= n)
        {
            res = fmin(res, fabs(i - arr_sum));
        }
    }
    printf("%.3f", res);
    return 0;
}
