#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Read the number of points (N) from the user
    int N;
    cin >> N;
    
    // Initialize a vector to store the coordinates of the points
    vector<vector<int>> pos(N, vector<int>(2));
    
    // Loop to read the coordinates of each point
    for (int i = 0; i < N; i++) {
        // Read the x and y coordinates for the i-th point
        cin >> pos[i][0] >> pos[i][1];
    }
    
    // Initialize a variable to accumulate the sum of distances
    double sum = 0;
    
    // Loop through each pair of points to calculate distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Skip the distance calculation if both points are the same
            if (i == j) continue;
            
            // Calculate the distance between point i and point j and add it to the sum
            sum += sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
        }
    }
    
    // Print the average distance by dividing the total sum by N
    cout << sum / N << endl;

    return 0;
}

// <END-OF-CODE>
