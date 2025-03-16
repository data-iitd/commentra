
#include <stdio.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the console
    // (Note: This part is not possible in C, so we will assume the input is provided as command-line arguments)
    
    // Read the number of points (N) from the command-line arguments
    int N = atoi(argv[1]);
    
    // Initialize a 2D array to store the coordinates of the points
    int pos[N][2];
    
    // Loop to read the coordinates of each point from the command-line arguments
    for (int i = 0; i < N; i++) {
        // Read the x and y coordinates for the i-th point
        pos[i][0] = atoi(argv[2*i+2]);
        pos[i][1] = atoi(argv[2*i+3]);
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
    printf("%f\n", sum / N);
    
    // End of code
    return 0;
}

// Method to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

