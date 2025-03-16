#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    // Allocate memory for the coordinates
    double *X = malloc(N * sizeof(double));
    double *Y = malloc(N * sizeof(double));
    
    // Read the coordinates
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &X[i], &Y[i]);
    }
    
    // Iterate over each point
    for (int i = 0; i < N; i++) {
        double D[N - 1];
        int index = 0;

        // Calculate angles from the current point (X[i], Y[i]) to all other points
        for (int j = 0; j < N; j++) {
            if (j != i) {
                D[index++] = atan2(X[j] - X[i], Y[j] - Y[i]);
            }
        }

        // Sort the angles
        qsort(D, N - 1, sizeof(double), compare);
        
        // Append the angle that wraps around (2*pi)
        D[index] = D[0] + 2 * M_PI;
        
        // Initialize the answer for the current point
        double ans = 0;

        // Calculate the gaps between consecutive angles
        for (int k = 0; k < index; k++) {
            double a = D[k];
            double b = D[k + 1];
            // Check if the gap is greater than or equal to pi
            if (b - a >= M_PI) {
                // Update the answer with the size of the gap minus pi
                ans = (b - a) - M_PI;
            }
        }

        // Print the normalized answer (as a fraction of 2*pi)
        printf("%lf\n", ans / (2 * M_PI));
    }

    // Free allocated memory
    free(X);
    free(Y);
    
    return 0;
}

// <END-OF-CODE>
