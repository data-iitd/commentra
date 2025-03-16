#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the absolute difference between two float numbers.
<<<<<<< HEAD
double abs_diff(double n1, double n2) {
=======
float AbsDiffFloat(float n1, float n2) {
>>>>>>> 98c87cb78a (data updated)
    return fabs(n1 - n2);
}

int main() {
    int n;
<<<<<<< HEAD
    double t, a;

    // Read values for n, t, and a.
    scanf("%d %lf %lf", &n, &t, &a);
    
    double *heights = (double *)malloc(n * sizeof(double)); // Allocate memory for heights.
    
    // Read the list of heights.
    for (int i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    double min_diff = abs_diff(t - heights[0] * 0.006, a); // Calculate the initial minimum difference.
    int min_idx = 0; // Initialize the index of the minimum difference.

    // Iterate through the heights starting from the second element.
    for (int i = 1; i < n; i++) {
        double diff = abs_diff(t - heights[i] * 0.006, a); // Calculate the difference for the current height.
        if (diff < min_diff) { // Update the minimum difference and index if a smaller difference is found.
            min_diff = diff;
            min_idx = i;
        }
    }

    printf("%d\n", min_idx + 1); // Print the index (plus one for 1-based indexing).
=======
    float t, a;

    // Read values for n, t, and a.
    scanf("%d %f %f", &n, &t, &a);
    
    float *heights = (float *)malloc(n * sizeof(float)); // Allocate memory for heights.
    
    // Read the list of heights.
    for (int i = 0; i < n; i++) {
        scanf("%f", &heights[i]);
    }

    float minDiff = AbsDiffFloat(t - heights[0] * 0.006, a); // Calculate the initial minimum difference.
    int minIdx = 0; // Initialize the index of the minimum difference.

    // Iterate through the heights starting from the second element.
    for (int i = 1; i < n; i++) {
        float diff = AbsDiffFloat(t - heights[i] * 0.006, a); // Calculate the difference for the current height.
        if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found.
            minDiff = diff;
            minIdx = i;
        }
    }

    printf("%d\n", minIdx + 1); // Print the index (plus one for 1-based indexing).
>>>>>>> 98c87cb78a (data updated)

    free(heights); // Free the allocated memory.
    return 0;
}

<<<<<<< HEAD
/* <END-OF-CODE> */
=======
// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
