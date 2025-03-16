#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, o;
    double arr[1000], arr_sum = 0, res = 2e9;

    // Input the number of elements (n)
    scanf("%d", &n);

    // Input the array elements
    for (i = 0; i < n; i++)
        scanf("%lf", &arr[i]);

    // Extract fractional parts and sort them
    for (i = 0; i < n; i++)
        if (arr[i] - (int)arr[i] != 0)
            arr[i] = arr[i] - (int)arr[i];
    qsort(arr, n, sizeof(double), cmp);

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    o = 2 * n - n;

    // Sum of the sorted fractional parts
    for (i = 0; i < n; i++)
        arr_sum += arr[i];

    // Iterate to find the best position
    for (i = 0; i < n + o; i++)
        if (i + o >= n)
            res = fmin(res, fabs(i - arr_sum));

    // Print the result with three decimal places
    printf("%.3f", res);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(double *)a - *(double *)b;
}

