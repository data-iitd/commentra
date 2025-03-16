#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n, t, i;
    double a, minDiff, h, diff;

    // Read input values
    scanf("%d %d", &n, &t);
    double heights[n];
    for (i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }
    scanf("%lf", &a);

    // Initialize variables for minimum difference and index
    minDiff = fabs(t - heights[0] * 0.006);
    int minIdx = 0;

    // Iterate through the remaining heights and find the minimum difference
    for (i = 1; i < n; i++) {
        h = heights[i];
        diff = fabs(t - h * 0.006);

        // Update minimum difference and index if the current difference is smaller
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    // Print the result
    printf("%d\n", minIdx + 1);

    return 0;
}
