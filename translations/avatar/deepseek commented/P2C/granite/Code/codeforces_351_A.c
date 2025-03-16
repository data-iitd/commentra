
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);  // Input the number of elements (n)

    double arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);  // Input the array elements
    }

    // Extract fractional parts and sort them
    double temp[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        double f = arr[i] - floor(arr[i]);
        if (f!= 0) {
            temp[count++] = f;
        }
    }
    qsort(temp, count, sizeof(double));

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    int o = 2 * n - count;

    // Sum of the sorted fractional parts
    double arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += temp[i];
    }

    // Initialize the result variable to a very large number
    double res = 1e9;

    // Iterate to find the best position
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    printf("%.3f\n", res);

    return 0;
}
