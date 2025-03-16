#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    double angleA = *(double *)a;
    double angleB = *(double *)b;
    return (angleA > angleB) - (angleA < angleB);
}

int main() {
    // Read the number of points N
    int N;
    scanf("%d", &N);
    
    // Initialize arrays to store the x and y coordinates of the points
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));
    
    // Read the coordinates of the points from user input
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    // Iterate over each point to calculate the angles with respect to other points
    for (int i = 0; i < N; ++i) {
        // Create an array to store the angles (thetas) for the current point
        double *thetas = (double *)malloc((N - 1) * sizeof(double));
        
        // Calculate the angle between the current point and all other points
        int index = 0;
        for (int j = 0; j < N; ++j) {
            // Skip the current point itself
            if (i == j) continue;
            
            // Calculate the angle using atan2 and add it to the array
            thetas[index++] = atan2(y[j] - y[i], x[j] - x[i]);
        }
        
        // Sort the angles in ascending order
        qsort(thetas, N - 1, sizeof(double), compare);
        
        // Add the angle that wraps around (2 * PI) to handle circularity
        thetas[index] = thetas[0] + 2 * M_PI;
        
        // Initialize a variable to find the maximum angle difference
        double ans = 0;
        
        // Calculate the maximum angle difference between consecutive angles
        for (int k = 0; k < N - 2; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }
        
        // Output the result as a fraction of the full circle (2 * PI)
        printf("%lf\n", ans / (M_PI * 2));
        
        // Free the allocated memory for thetas
        free(thetas);
    }
    
    // Free the allocated memory for x and y
    free(x);
    free(y);
    
    return 0;
}

// <END-OF-CODE>
