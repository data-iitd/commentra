

#include <stdio.h>
#include <math.h>

int main() {
    int n, minIdx = 0;
    float t, a, minDiff = 1000000000.0;
    float heights[100000];

    // Read input values
    scanf("%d %f %f", &n, &t, &a);

    // Initialize heights array
    for (int i = 0; i < n; i++) {
        scanf("%f", &heights[i]);
    }

    // Calculate minimum difference and index
    for (int i = 0; i < n; i++) {
        float diff = fabs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i + 1;
        }
    }

    // Print the result
    printf("%d\n", minIdx);

    return 0;
}

