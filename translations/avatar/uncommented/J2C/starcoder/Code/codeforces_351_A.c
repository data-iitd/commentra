#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    double arr[2*n];
    int non_int = 0;
    double sum_before = 0, sum = 0;
    for(int i = 0; i < 2*n; i++)
    {
        scanf("%lf", &arr[i]);
        sum_before += arr[i];
        if(arr[i]!= floor(arr[i]))
            non_int++;
        sum += floor(arr[i]);
    }
    double max_sum = (double)min(n, non_int) + sum;
    double min_sum = (double)max(0, non_int - n) + sum;
    double ans;
    if(min_sum > sum_before)
        ans = min_sum - sum_before;
    else if(max_sum < sum_before)
        ans = sum_before - max_sum;
    else
    {
        double x = sum_before - floor(sum_before);
        ans = min(1-x, x);
    }
    printf("%.3lf", ans);
    return 0;
}

