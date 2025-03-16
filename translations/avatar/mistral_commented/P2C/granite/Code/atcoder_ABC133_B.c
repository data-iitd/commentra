
#include <stdio.h>
#include <math.h>

int main() {
    // Taking the number of points, n, and the number of dimensions, d, as input
    int n, d;
    scanf("%d %d", &n, &d);

    // Initializing a 2D array 'points' of size 'n' x 'd' to store the coordinates of each point
    int points[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &points[i][j]);
        }
    }

    // Defining a function 'dist' to calculate the Euclidean distance between two points
    double dist(int x[], int y[]) {
        // Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
        double tmp = 0.0;

        // Iterating through each dimension 'i' from 0 to 'd'
        for (int i = 0; i < d; i++) {
            // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
            tmp += pow(x[i] - y[i], 2);
        }

        // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
        return sqrt(tmp);
    }

    // Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
    int count = 0;

    // Iterating through each point 'i' in 'points'
    for (int i = 0; i < n; i++) {
        // Iterating through each point 'j' from 'i+1' to the last point in 'points'
        for (int j = i + 1; j < n; j++) {
            // Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
            if (dist(points[i], points[j]) == (int)dist(points[i], points[j])) {
                // Incrementing the 'count' variable if the condition is true
                count++;
            }
        }
    }

    // Printing the final value of 'count'
    printf("%d\n", count);

    return 0;
}
