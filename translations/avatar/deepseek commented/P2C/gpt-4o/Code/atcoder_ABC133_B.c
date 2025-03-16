#include <stdio.h>
#include <math.h>

int main() {
    int n, d;
    
    // Read the number of points and the dimension from the input
    scanf("%d %d", &n, &d);
    
    // Declare a 2D array to store the points
    int points[n][d];
    
    // Read n points, each with d coordinates
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &points[i][j]);
        }
    }
    
    // Initialize a counter to keep track of pairs with integer distances
    int count = 0;

    // Iterate over all pairs of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the Euclidean distance between points[i] and points[j]
            double tmp = 0.0;
            for (int k = 0; k < d; k++) {
                tmp += (points[i][k] - points[j][k]) * (points[i][k] - points[j][k]);
            }
            double distance = sqrt(tmp);
            
            // Check if the distance is an integer
            if (distance == (int)distance) {
                count++;
            }
        }
    }

    // Print the total count of pairs with integer distances
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
