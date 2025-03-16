#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double arr[2 * n];
    int non_int = 0;
    double sum_before = 0, sum = 0;
    
    char buffer[1000];
    fgets(buffer, 1000, stdin); // Read the newline character
    fgets(buffer, 1000, stdin);
    
    char *token = strtok(buffer, " ");
    for (int i = 0; i < 2 * n; i++) {
        arr[i] = atof(token);
        sum_before += arr[i];
        if (fmod(arr[i], 1) != 0)
            non_int++;
        sum += floor(arr[i]);
        token = strtok(NULL, " ");
    }
    
    double max_sum = fmin(n, non_int) + sum;
    double min_sum = fmax(0, non_int - n) + sum;
    
    double ans;
    if (min_sum > sum_before)
        ans = (min_sum - sum_before);
    else if (max_sum < sum_before)
        ans = (sum_before - max_sum);
    else {
        double x = sum_before - floor(sum_before);
        ans = fmin(1 - x, x);
    }
    
    printf("%.3f\n", ans);
    
    return 0;
}
