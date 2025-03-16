#include <stdio.h>
#include <math.h> // Including math library for sqrt function

// Function to calculate the Euclidean distance between two points
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int N; // Variable to store the number of points
    scanf("%d", &N); // Reading the number of points from the user

    int pos[N][2]; // Creating a 2D array of size N x 2 to store the x and y coordinates of the points

    for (int i = 0; i < N; i++) { // Iterating through each point
        scanf("%d %d", &pos[i][0], &pos[i][1]); // Reading the x and y coordinates of the point
    }

    double sum = 0; // Initializing the sum variable to 0

    for (int i = 0; i < N; i++) { // Iterating through each point
        for (int j = 0; j < N; j++) { // Iterating through all other points except the current one
            if (i == j) continue; // Skipping the current point when comparing it with itself
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]); // Adding the distance between the current and the other point to the sum
        }
    }

    printf("%lf\n", sum / N); // Printing the average distance between all pairs of points
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
