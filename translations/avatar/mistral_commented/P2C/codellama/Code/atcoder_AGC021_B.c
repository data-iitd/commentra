#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read the input from standard input and parse it into two variables: N (number of points) and XY (a list of tuples representing the coordinates of N points)
    int N;
    scanf("%d", &N);
    int XY[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &XY[i][0], &XY[i][1]);
    }

    // Transpose the XY list so that it becomes a list of lists, where each inner list contains the x and y coordinates of a point
    int XY_transposed[2][N];
    for (int i = 0; i < N; i++) {
        XY_transposed[0][i] = XY[i][0];
        XY_transposed[1][i] = XY[i][1];
    }

    // Iterate through each point in XY and calculate the angles between it and all other points
    for (int i = 0; i < N; i++) {
        // Calculate the differences between the x and y coordinates of the current point and all other points
        double D[N];
        for (int j = 0; j < N; j++) {
            if (i != j) {
                D[j] = atan2(XY_transposed[0][j] - XY_transposed[0][i], XY_transposed[1][j] - XY_transposed[1][i]);
            }
        }

        // Append the angle between the current point and the first point (wrapped around if it's greater than pi)
        D[N] = D[0] + 2*pi;

        // Sort the angles
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (D[j] > D[k]) {
                    double temp = D[j];
                    D[j] = D[k];
                    D[k] = temp;
                }
            }
        }

        // Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
        for (int j = 0; j < N; j++) {
            // If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
            if (D[j+1] - D[j] >= pi) {
                ans += (D[j+1] - D[j]) - pi;
            }
        }
    }

    // Print the answer, which is the total area of the sectors divided by the total possible area (2π)
    printf("%.10f\n", ans / (2 * pi));

    return 0;
}

