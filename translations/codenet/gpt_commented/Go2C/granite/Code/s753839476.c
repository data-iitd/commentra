
#include <stdio.h>
#include <math.h>

int main() {
    // Initialize input/output handling
    FILE *input = stdin;
    FILE *output = stdout;

    // Read the number of heights, target temperature, and actual temperature
    int n;
    float t, a;
    fscanf(input, "%d %f %f", &n, &t, &a);

    // Read the heights as a slice of float
    float heights[n];
    for (int i = 0; i < n; i++) {
        fscanf(input, "%f", &heights[i]);
    }

    // Initialize minimum difference and index for tracking the closest height
    float minDiff = fabs(t - heights[0] * 0.006 - a);
    int minIdx = 0;

    // Iterate through the heights to find the one with the minimum temperature difference
    for (int i = 1; i < n; i++) {
        float diff = fabs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    // Output the 1-based index of the closest height
    fprintf(output, "%d\n", minIdx + 1);

    return 0;
}
