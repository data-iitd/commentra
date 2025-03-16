
// Importing necessary C utility libraries
#include <stdio.h>  // For reading input from the console
#include <stdlib.h>  // For dynamic memory allocation
#include <math.h>  // For mathematical functions

// Main function where the program starts
int main() {
    // Creating a Scanner object for reading input from the console
    // (Note: This is not possible in C, so we will read input manually)

    // Reading the number of points (N) from the input
    int N;
    scanf("%d", &N);

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    double *x = (double*)malloc(N * sizeof(double));
    double *y = (double*)malloc(N * sizeof(double));

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);  // Reading the x coordinate
        scanf("%lf", &y[i]);  // Reading the y coordinate
    }

    // Calculating the angles between each pair of points and storing them in a list called thetas
    double *thetas = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; ++i) {
        thetas[i] = 0;  // Initializing the angles to zero

        // Calculating the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;  // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas[i] += atan2(y[j] - y[i], x[j] - x[i]);
        }

        // Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas[i] += 2 * M_PI;
    }

    // Sorting the list of angles in ascending order
    qsort(thetas, N, sizeof(double), compare);

    // Finding the maximum angle between consecutive angles and calculating the answer
    double ans = 0;
    for (int k = 0; k < N - 1; ++k) {
        ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
    }

    // Printing the answer
    printf("%lf\n", ans / (2 * M_PI));

    // Freeing the dynamically allocated memory
    free(x);
    free(y);
    free(thetas);

    return 0;
}

// Function for comparing two double values for sorting
int compare(const void *a, const void *b) {
    double da = *(double*)a;
    double db = *(double*)b;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

// End of code
