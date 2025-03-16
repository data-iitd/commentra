
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    double arr[2*n];
    int non_int = 0, sum_before = 0, sum = 0;
    for(int i = 0; i < 2*n; i++)
    {
        scanf("%lf", &arr[i]);
        sum_before += arr[i];
        if(arr[i]!= (int)arr[i]) non_int++;
        sum += (int)arr[i];
    }
    double max_sum = (non_int < n)? (n - non_int) + sum : sum;
    double min_sum = (non_int > n)? (non_int - n) + sum : 0;
    double ans;
    if(min_sum > sum_before) ans = (min_sum - sum_before);
    else if(max_sum < sum_before) ans = (sum_before - max_sum);
    else
    {
        double x = sum_before - (int)sum_before;
        ans = (x < 1)? (1 - x) : x;
    }
    printf("%.3f", ans);
    return 0;
}

