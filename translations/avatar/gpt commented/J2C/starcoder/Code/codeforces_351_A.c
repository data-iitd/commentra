#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char *str = (char *)malloc(sizeof(char) * 1000000);
    scanf("%s", str);
    int non_int = 0;
    double sum_before = 0, sum = 0;
    double *arr = (double *)malloc(sizeof(double) * 2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        double num;
        scanf("%lf", &num);
        sum_before += num;
        if (num!= (int)num)
            non_int++;
        sum += (int)num;
        arr[i] = num;
    }
    double max_sum = (double)non_int + sum;
    double min_sum = (double)(non_int - n) + sum;
    double ans;
    if (min_sum > sum_before)
        ans = min_sum - sum_before;
    else if (max_sum < sum_before)
        ans = sum_before - max_sum;
    else
    {
        double x = sum_before - (int)sum_before;
        ans = (double)fmin(1 - x, x);
    }
    printf("%.3lf", ans);
    return 0;
}

