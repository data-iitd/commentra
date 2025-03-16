#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n;
    double num, sum_before = 0, sum = 0;
    int non_int = 0;
    char input[1000];
    char *token;
    double arr[2000];

    // Reading the number of test cases
    fgets(input, sizeof(input), stdin);
    n = atoi(input);

    // Reading the elements of the array
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        num = atof(token);
        sum_before += num;
        if (num != floor(num)) non_int++;
        sum += floor(num);
        arr[i++] = num;
        token = strtok(NULL, " ");
    }

    // Calculating the maximum and minimum sums
    double max_sum = fmin(n, non_int) + sum;
    double min_sum = fmax(0, non_int - n) + sum;

    // Calculating the answer based on the given conditions
    double ans;
    if (min_sum > sum_before) ans = (min_sum - sum_before);
    else if (max_sum < sum_before) ans = (sum_before - max_sum);
    else {
        double x = sum_before - floor(sum_before);
        ans = fmin(1 - x, x);
    }

    // Printing the answer
    printf("%.3f\n", ans);

    return 0;
}
