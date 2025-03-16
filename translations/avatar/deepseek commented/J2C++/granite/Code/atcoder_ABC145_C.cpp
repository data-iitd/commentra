
#include <iostream> // Include the necessary libraries
#include <cmath>

using namespace std;

int main() {
    int N; // Number of points
    cin >> N; // Read the number of points

    int pos[N][2]; // 2D array to store coordinates

    // Read coordinates of points
    for (int i = 0; i < N; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }

    double sum = 0; // Initialize sum to store the total distance

    // Calculate the sum of distances between all pairs of points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // Skip the diagonal elements
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]); // Add distance to sum
        }
    }

    // Calculate and print the average distance
    cout << sum / N << endl;

    return 0;
}

// Helper function to calculate the Euclidean distance between two points
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

