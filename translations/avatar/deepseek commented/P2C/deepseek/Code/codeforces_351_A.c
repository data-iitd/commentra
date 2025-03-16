#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Extract fractional parts and sort them
    float fractional_parts[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        float fractional = arr[i] - (int)arr[i];
        if (fractional != 0) {
            fractional_parts[count++] = fractional;
        }
    }

    // Sort the fractional parts
    qsort(fractional_parts, count, sizeof(float), compare);

    // Calculate the number of elements to be added
    int o = 2 * n - count;

    // Sum of the sorted fractional parts
    float arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += fractional_parts[i];
    }

    // Initialize the result variable to a very large number
    float res = 2e9;

    // Iterate to find the best position
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = (res < abs(i - arr_sum)) ? res : abs(i - arr_sum);
        }
    }

    // Print the result with three decimal places
    printf("%.3f\n", res);

    return 0;
}
