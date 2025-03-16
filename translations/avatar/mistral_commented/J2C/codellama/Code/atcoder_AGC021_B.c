// Including necessary C utility headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function where the program starts
int main() {
    // Creating a variable for reading input from the console
    int N;

    // Reading the number of points (N) from the input
    scanf("%d", &N);

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    int x[N];
    int y[N];

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Calculating the angles between each pair of points and storing them in a list called thetas
    double thetas[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;  // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas[i][j] = atan2(y[j] - y[i], x[j] - x[i]);
        }
    }

    // Sorting the list of angles in ascending order
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (thetas[i][j] > thetas[i][j + 1]) {
                double temp = thetas[i][j];
                thetas[i][j] = thetas[i][j + 1];
                thetas[i][j + 1] = temp;
            }
        }
    }

    // Adding the angle between the last point and the first point (wrapped around 2π) to the list
    for (int i = 0; i < N; ++i) {
        thetas[i][N - 1] = thetas[i][0] + 2 * M_PI;
    }

    // Finding the maximum angle between consecutive angles and calculating the answer
    double ans = 0;
    for (int k = 0; k < N - 1; ++k) {
        ans = fmax(ans, thetas[k + 1][k] - thetas[k][k] - M_PI);
    }

    // Printing the answer
    printf("%.10lf\n", ans / (M_PI * 2));

    // Ending the code
    return 0;
}
