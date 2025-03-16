#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N); // Reading the number of points
    int pos[N][2]; // Initializing a 2D array to store coordinates

    // Reading coordinates of points
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]); // Reading x-coordinate and y-coordinate
    }

    double sum = 0; // Initializing sum to store the total distance

    // Calculating the sum of distances between all pairs of points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // Skipping the diagonal elements
            sum += sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2)); // Adding distance to sum
        }
    }

    // Calculating and printing the average distance
    printf("%.15f\n", sum / N);

    return 0;
}
