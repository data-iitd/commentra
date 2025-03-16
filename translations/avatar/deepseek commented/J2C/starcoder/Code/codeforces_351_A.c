
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char *line = (char *) malloc(sizeof(char) * 1000);
    scanf("%s", line);
    char *token = strtok(line, " ");
    double *arr = (double *) malloc(sizeof(double) * 2 * n);
    int non_int = 0;
    double sum_before = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        double num = atof(token);
        sum_before += num;
        if (num!= floor(num)) non_int++;
        sum += floor(num);
        arr[i] = num;
        token = strtok(NULL, " ");
    }
    double max_sum = (double) (n < non_int) + sum;
    double min_sum = (double) (non_int - n > 0) + sum;
    double ans;
    if (min_sum > sum_before)
        ans = min_sum - sum_before;
    else if (max_sum < sum_before)
        ans = sum_before - max_sum;
    else {
        double x = sum_before - floor(sum_before);
        ans = (double) (1 - x < x)? 1 - x : x;
    }
    printf("%.3f", ans);
    return 0;
}

