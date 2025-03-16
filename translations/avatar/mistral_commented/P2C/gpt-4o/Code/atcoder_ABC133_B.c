#include <stdio.h>
#include <math.h>

// Function to calculate the Euclidean distance between two points
double dist(int *x, int *y, int d) {
    double tmp = 0.0;

    // Iterating through each dimension
    for (int i = 0; i < d; i++) {
        // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }

    // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
    return sqrt(tmp);
}

int main() {
    int n, d;

    // Taking the number of points, n, and the number of dimensions, d, as input
    scanf("%d %d", &n, &d);

    // Initializing a 2D array 'points' to store the coordinates of each point
    int points[n][d];

    // Taking the coordinates of each point as input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &points[i][j]);
        }
    }

    // Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
    int count = 0;

    // Iterating through each point 'i' in 'points'
    for (int i = 0; i < n; i++) {
        // Iterating through each point 'j' from 'i+1' to the last point in 'points'
        for (int j = i + 1; j < n; j++) {
            // Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
            if (dist(points[i], points[j], d) == (int)dist(points[i], points[j], d)) {
                // Incrementing the 'count' variable if the condition is true
                count++;
            }
        }
    }

    // Printing the final value of 'count'
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
