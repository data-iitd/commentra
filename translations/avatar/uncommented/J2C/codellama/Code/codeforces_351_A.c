
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    double sum_before, sum, ans;
    int non_int;
    double *arr;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    n = atoi(line);
    free(line);

    read = getline(&line, &len, stdin);
    arr = (double *)malloc(sizeof(double) * 2 * n);
    non_int = 0;
    sum_before = 0;
    sum = 0;
    char *token;
    char *saveptr;
    token = strtok_r(line, " ", &saveptr);
    while (token != NULL)
    {
        double num = atof(token);
        sum_before += num;
        if (num != floor(num))
            non_int++;
        sum += floor(num);
        arr[non_int] = num;
        token = strtok_r(NULL, " ", &saveptr);
    }
    free(line);

    double max_sum = fmin(n, non_int) + sum;
    double min_sum = fmax(0, non_int - n) + sum;

    if (min_sum > sum_before)
        ans = (min_sum - sum_before);
    else if (max_sum < sum_before)
        ans = (sum_before - max_sum);
    else
    {
        double x = sum_before - floor(sum_before);
        ans = fmin(1 - x, x);
    }

    printf("%.3f", ans);

    free(arr);

    return 0;
}

