#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate absolute difference between two float numbers
double AbsDiffDouble(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n;
    double t, a;

    // Read input values
    scanf("%d %lf %lf", &n, &t, &a);

    // Initialize variables for heights and minimum difference
    double *heights = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    double minDiff = AbsDiffDouble(t - heights[0] * 0.006, a);
    int minIdx = 0;

    // Iterate through the remaining heights and find the minimum difference
    for (int i = 1; i < n; i++) {
        // Calculate the difference between the target and the height
        double diff = AbsDiffDouble(t - heights[i] * 0.006, a);

        // Update minimum difference and index if the current difference is smaller
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    // Print the result (1-based index)
    printf("%d\n", minIdx + 1);

    // Free allocated memory
    free(heights);

    return 0;
}

// <END-OF-CODE>
