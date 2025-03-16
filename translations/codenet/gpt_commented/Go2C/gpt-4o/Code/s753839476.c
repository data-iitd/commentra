#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double AbsDiffDouble(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    // Initialize input/output handling
    int n;
    double t, a;

    // Read the number of heights, target temperature, and actual temperature
    scanf("%d %lf %lf", &n, &t, &a);
    
    // Allocate memory for heights
    double *heights = (double *)malloc(n * sizeof(double));
    
    // Read the heights
    for (int i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    // Initialize minimum difference and index for tracking the closest height
    double minDiff = AbsDiffDouble(t - heights[0] * 0.006, a);
    int minIdx = 0;

    // Iterate through the heights to find the one with the minimum temperature difference
    for (int i = 1; i < n; i++) {
        double diff = AbsDiffDouble(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i; // Update the index of the closest height
        }
    }

    // Output the 1-based index of the closest height
    printf("%d\n", minIdx + 1);

    // Free allocated memory
    free(heights);

    return 0;
}

// <END-OF-CODE>
