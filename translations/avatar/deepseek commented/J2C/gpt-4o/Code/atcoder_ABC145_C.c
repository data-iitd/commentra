#include <stdio.h>
#include <math.h> // For sqrt function

// Function to calculate the Euclidean distance between two points
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int N; // Number of points
    scanf("%d", &N); // Reading the number of points
    int pos[N][2]; // 2D array to store coordinates

    // Reading coordinates of points
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]); // Reading x and y coordinates
    }

    double sum = 0; // Initializing sum to store the total distance

    // Calculating the sum of distances between all pairs of points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // Skipping the diagonal elements
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]); // Adding distance to sum
        }
    }

    // Calculating and printing the average distance
    printf("%lf\n", sum / N); // Printing the average distance

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
