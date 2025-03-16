#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparator function for sorting angles
int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Reading the number of points (N) from the input
    int N;
    scanf("%d", &N);

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);  // Reading the x and y coordinates
    }

    // Allocating memory for the angles
    double *thetas = (double *)malloc((N + 1) * sizeof(double));  // +1 for the wrapped angle

    // Calculating the angles between each pair of points
    for (int i = 0; i < N; ++i) {
        int count = 0;  // Counter for the number of angles

        // Calculating the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;  // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas[count++] = atan2(y[j] - y[i], x[j] - x[i]);
        }

        // Sorting the list of angles in ascending order
        qsort(thetas, count, sizeof(double), compare);

        // Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas[count] = thetas[0] + 2 * M_PI;

        // Finding the maximum angle between consecutive angles
        double ans = 0;
        for (int k = 0; k < count - 1; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }

        // Printing the answer
        printf("%lf\n", ans / (M_PI * 2));
    }

    // Freeing allocated memory
    free(x);
    free(y);
    free(thetas);

    return 0;
}

// <END-OF-CODE>
