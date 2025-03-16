#include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    // Read the number of points (N) from the user
    int N;
    scanf("%d", &N);
    
    // Initialize a 2D array to store the coordinates of the points
    int pos[N][2];
    
    // Loop to read the coordinates of each point
    for (int i = 0; i < N; i++) {
        // Read the x and y coordinates for the i-th point
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    
    // Initialize a variable to accumulate the sum of distances
    double sum = 0;
    
    // Loop through each pair of points to calculate distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Skip the distance calculation if both points are the same
            if (i == j) continue;
            
            // Calculate the distance between point i and point j and add it to the sum
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
        }
    }
    
    // Print the average distance by dividing the total sum by N
    printf("%lf\n", sum / N);
    
    return 0;
}

// <END-OF-CODE>
